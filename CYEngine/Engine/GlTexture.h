#pragma once
#include "CObject.h"
#include<iostream>
#include "OpenGLMacros.h"



USING_STD;
class GlTexture :
    public CObject
{
private:
    unsigned char* _data = nullptr;
    int _width = 0;
    int _height = 0;
    int _nrChannels = 0;
    GLuint* _textures = 0;
    unsigned char _textureSlot = 0;
    GLenum _wrapS = GL_REPEAT;
    GLenum _wrapT = GL_REPEAT;
    GLenum _type = GL_TEXTURE_2D;
    GLenum _format= GL_RGB;
    GLint _internalFormat= GL_RGB;
    int _textureCount = 0;
public:
    
    GlTexture(const char* url, GLenum format, GLint internalFormat, bool isFlip = true);

    void genTextureBuffer(unsigned char slot, GLenum type, int count = 1);
    void setTextureWrapMode(GLenum wrap_s, GLenum wrap_t);

    void bindTexture();

    int getSlot() const {
        return _textureSlot;
    }

    enum Slot
    {
        DIFFUSE,
        SPECULAR,
        EMISSION
    };


    virtual ~GlTexture();

};

