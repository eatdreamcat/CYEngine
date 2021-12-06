#pragma once
#include "CObject.h"
#include <stb_image.h>
#include<iostream>
#include "OpenGLMacros.h"

USING_STD;
class GlTexture :
    public CObject
{
private:
    unsigned char* data;
    int width;
    int height;
    int nrChannels;
    GLuint* textures;
    int textureCount;
public:
    
    GlTexture() :data(nullptr), width(0), height(0), nrChannels(0),textures(0),textureCount(0) {
        
    };

    GlTexture(const char* url,bool isFlip = true):textureCount(0),textures(0) {
        stbi_set_flip_vertically_on_load(isFlip);
        data = stbi_load(url, &width, &height, &nrChannels, 0);

        if (data)
        {
          
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
    };

    bool loadTexture(const char* url, bool isFlip = true);

    void genTextureBuffer(int count = 1);

    virtual ~GlTexture() {
        stbi_image_free(data);
        delete[] textures;
        textures = nullptr;
        data = nullptr;
    }

};

