#ifndef ASSETS_MODEL_HPP
#define ASSETS_MODEL_HPP

#include <GL/glew.h>

#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

#include <string>
#include <vector>

class Model {
  void LoadModel(const std::string& path);
  void ProcessNode(aiNode *node, const aiScene *scene);
public:
  std::vector<GLfloat> vertices;
  std::vector<GLuint> indices;
  Model(const std::string& path);
};

#endif