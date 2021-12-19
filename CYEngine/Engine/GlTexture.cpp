#include "GlTexture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

GlTexture::GlTexture(const char* url, GLenum format, GLint internalFormat, bool isFlip)
{
	this->_internalFormat = internalFormat;
	this->_format = format;

	stbi_set_flip_vertically_on_load(isFlip);
	_data = stbi_load(url, &_width, &_height, &_nrChannels, 0);

	if (_data)
	{

	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

}

void GlTexture::bindTexture() {
	if (_textures != nullptr) {
		GlActiveTexture(GL_TEXTURE0 + this->_textureSlot);
		GlBindTexture(this->_type, _textures[0]);
	}
}

GlTexture::~GlTexture()
{
	{
		stbi_image_free(_data);
		delete[] _textures;
		_textures = nullptr;
		_data = nullptr;
	}
}


void GlTexture::genTextureBuffer(unsigned char slot, GLenum type, int count)
{
	_textureCount = count;
	this->_textureSlot = slot;
	this->_type = type;
	if (_textures == nullptr) {
		_textures = new GLuint[count];

	}
	else
	{

	}

	GlGenTextures(count, _textures);

	bindTexture();

	if (_data) {

		GlTexImage2D(this->_type, 0, _internalFormat, _width, _height, _format, GL_UNSIGNED_BYTE, _data);
	}
}

void GlTexture::setTextureWrapMode(GLenum wrap_s, GLenum wrap_t)
{
	bindTexture();
	GlTexParameteri(_type, GL_TEXTURE_WRAP_T, wrap_t);
	GlTexParameteri(_type, GL_TEXTURE_WRAP_S, wrap_s);
}

