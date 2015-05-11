#include "Sphere.h"

Sphere::Sphere(GLfloat detail){
  this->detail = detail;
  int size = detail*detail*9*2;
  GLfloat* verticies = new GLfloat[size];
  GLfloat zc = 0, yc = 0, xc= 0, angInc = 2*M_PI/detail;
  GLfloat decrement = 1.0f/detail;
  int count = 0;
  for(zc = 1.0f; zc > -1.0f; zc -= decrement){
    GLfloat nextZc = zc - decrement;
    GLfloat nextR = 1.0f - glm::abs(nextZc);
    GLfloat r = 1.0f - glm::abs(zc);
    for(GLfloat ang = 0.0f; ang < 2*M_PI; ang += angInc){
      GLfloat yc = r*glm::sin(ang);
      GLfloat xc = r*glm::cos(ang);
      GLfloat leftYc = nextR*glm::sin(ang);
      GLfloat leftXc = nextR*glm::cos(ang);
      GLfloat rightYc = nextR*glm::sin(ang + angInc);
      GLfloat rightXc = nextR*glm::cos(ang + angInc);
      
      verticies[count+0] = xc;
      verticies[count+1] = yc;
      verticies[count+2] = zc;

      verticies[count+3] = leftXc;
      verticies[count+4] = leftYc;
      verticies[count+5] = nextZc;

      verticies[count+6] = rightXc;
      verticies[count+7] = rightYc;
      verticies[count+8] = nextZc;

      count += 9;
    } 
  }
  std::cout << "Count: " << count << "\n";
  getData()->setVertexData(verticies, size);
}

void Sphere::update(double delta){
  rotate(2.0f);
}
