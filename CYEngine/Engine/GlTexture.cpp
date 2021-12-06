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

void GlTexture::genTextureBuffer(int count)
{
    textureCount = count;
    if (textures == nullptr) {
        textures = new GLuint[count];
       
    }
    else
    {

    }
   
    GlGenTextures(count, textures);
  
   GlBindTexture(GL_TEXTURE0, textures[0]);

    if (data) {

        GlTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
        GlTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        GlTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    }
}

