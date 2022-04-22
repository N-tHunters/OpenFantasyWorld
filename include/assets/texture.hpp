#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>

#include <stb_image.h>

#include <string>
#include <unordered_map>

unsigned char* LoadImage(std::string path, int* width, int* height);

struct Texture {
    GLuint id;
    static std::unordered_map<std::string, Texture*> textures;
    static Texture* GetTexture(std::string name);
    Texture(GLuint id);
};

#endif
