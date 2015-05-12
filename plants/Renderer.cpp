#include "Renderer.h"
// Constructor
Renderer::Renderer(EventManager* evtmgr, int scrW, int scrH){
  std::cout << "Renderer init\n";
  this->screenW = scrW;
  this->screenH = scrH;
  
  camera = new Camera(evtmgr);
  camera->init(100,100,64);

  // Dark blue background
  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

  // Setup VAO
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  // Load shaders
  programID = LoadShaders( "shaders/SimpleTransform.vertexshader", "shaders/SingleColour.fragmentshader" );
  mvpMatID = glGetUniformLocation(programID, "MVP");

  // Setup perspective
  projection = glm::perspective(20.0f, 4.0f / 3.0f, 0.1f, 1000.0f);
  view = glm::lookAt(
    glm::vec3(0,0,16), 
    glm::vec3(0,0,0), 
    glm::vec3(0,1,0)
    );
  model = glm::mat4(1.0f);
  mvp = projection*view*model; 
} 
// Set entity render list
void Renderer::setEntities(vector<Entity*>* entities){
  this->entities = entities;
}

// Render entities
void Renderer::draw(){
  // Clear the screen
  glClear( GL_COLOR_BUFFER_BIT );

  // Use our shader
  glUseProgram(programID);

  // Enable drawing of vertex arrays
  glEnableVertexAttribArray(0);
  for(auto e = entities->begin(); e != entities->end(); e++){
    mvp = projection * camera->view() * (*e)->getModel();
    glUniformMatrix4fv(mvpMatID, 1, GL_FALSE, &mvp[0][0]);
    glBindBuffer(GL_ARRAY_BUFFER, *(*e)->getData()->getVertexBuffer());
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glDrawArrays(GL_TRIANGLES, 0, (*e)->getData()->numVerts()); // 3 indices starting at 0 -> 1 triangle
    
  }
  glDisableVertexAttribArray(0);
}

// Return camera instance
Camera* Renderer::getCamera() {
  return camera;
}
