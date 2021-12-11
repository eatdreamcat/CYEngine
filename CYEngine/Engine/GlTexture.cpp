#include "GlTexture.h"

bool GlTexture::loadTexture(const char* url, bool isFlip)
{
    stbi_set_flip_vertically_on_load(isFlip);
    data = stbi_load(url, &width, &height, &nrChannels, 0);

    if (data)
    {
        return true;
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
        return false;
    }
    
}

void GlTexture::bindTexture() {
    if (textures != nullptr) {
        GlActiveTexture(this->target);
        GlBindTexture(this->type, textures[0]);
    }
}


void GlTexture::genTextureBuffer(GLenum target, GLenum type, int count)
{
    textureCount = count;
    this->target = target;
    this->type = type;
    if (textures == nullptr) {
        textures = new GLuint[count];
       
    }
    else
    {

    }
   
    GlGenTextures(count, textures);
  
    bindTexture();

    if (data) {

        GlTexImage2D(this->type, 0, format, width, height, format, GL_UNSIGNED_BYTE, data);
        GlGenerateMipmap(this->type);
    }
}

void GlTexture::setTextureWrapMode(GLenum wrap_s, GLenum wrap_t)
{
    bindTexture();
    GlTexParameteri(type, GL_TEXTURE_WRAP_T, wrap_t);
    GlTexParameteri(type, GL_TEXTURE_WRAP_S, wrap_s);
}

