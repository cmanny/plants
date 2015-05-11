#ifndef ENTITY_H
#define ENTITY_H
#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include "VertexData.h"

class Entity {
  protected:
    VertexData* data;
  private:
    glm::mat4 model;
    glm::vec3 rotationAxes;
    double x, y;
    double rotation;

  public:
    Entity();
    ~Entity();
    virtual void update(double delta) = 0;
    VertexData* getData();
    
    void move(double,double,double);
    void rotate(float);
    glm::mat4 getModel();

};

#endif
