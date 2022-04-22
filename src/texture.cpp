#include <texture.hpp>

unsigned char* LoadImage(std::string path, int* width, int* height) {
    int channels;

    unsigned char * result = stbi_load(path.c_str(), width, height, &channels, STBI_rgb);

    if (result == nullptr) {
        printf("ERROR::IMAGE_LOADING: File \"%s\" not found.\n", path.c_str());
        result = stbi_load("resources/textures/error.png", width, height, &channels, STBI_rgb);
    }

    return result;
}

std::unordered_map<std::string, Texture*> Texture::textures;

Texture::Texture(GLuint id) {
    this->id = id;
}

Texture* Texture::GetTexture(std::string name) {
    if (Texture::textures.find(name) != Texture::textures.end()) {
        return Texture::textures[name];
    }
    GLuint id;

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height;
    unsigned char* image = LoadImage("resources/textures" + name + ".png", &width, &height);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);

    Texture* texture = new Texture(id);
    return texture;
}