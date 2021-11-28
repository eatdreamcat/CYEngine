
#include "RenderEngine.h"
#include<iostream>
#include "Shader.h"
#include "OpenGLMacros.h"
#include <stb_image.h>
NS_CY_BEGIN
float vertices[] = {
	//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
	   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
	   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
};

unsigned int indices[] = {
	0,1,2,
	2,3,0
};



unsigned int VAO;
using namespace std;
Shader* shader;
	bool RenderEngine::createWindow(int width, int height, const char* title) {

	
	    GlfwInit();
		GlfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		GlfwWindowHint(GLEW_VERSION_MINOR, 3);
		GlfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		window = GlfwCreateWindow(width, height, title, NULL, NULL);
		if (window == nullptr) {
			cout << "window == nullptr" << endl;
			GlfwTerminate();
			return false;
		}
		GlfwMakeContextCurrent(window);
	
		if (GlewInit() != GLEW_OK) {
			cout << "glewInit() != GLEW_OK" << endl;
			GlfwTerminate();
			return false;
		}

		GlViewport(0, 0, width, height);
		//GlEnable(GL_CULL_FACE);
		// GlCullFace(GL_FRONT);
	    //GlPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		
		GlGenVertexArrays(1,&VAO);
		GlBindVertexArray(VAO);


		unsigned int VBO;
		GlGenBuffers(1, &VBO);
		GlBindBuffer(GL_ARRAY_BUFFER, VBO);
		GlBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		unsigned int EBO;
		GlGenBuffers(1, &EBO);
		GlBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		GlBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		unsigned int texture;
		GlGenTextures(1, &texture);
		GlBindTexture(GL_TEXTURE0, texture);
		int tex_width, tex_height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(R"(../Resources/content.png)", &tex_width, &tex_height, &nrChannels, 0);
		if (data)
		{
			GlTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex_width, tex_height, GL_RGBA, GL_UNSIGNED_BYTE, data);
		
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);

		/**
		* CREATE SHADER
		*/
		shader = new Shader(R"(../Engine/TestVertexShader.txt)", R"(../Engine/TestFragmentShader.txt)");


		
		GlVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		GlEnableVertexAttribArray(8);

		GlVertexAttribPointer(9, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
		GlEnableVertexAttribArray(9);

		GlVertexAttribPointer(10, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		GlEnableVertexAttribArray(10);

		return true;
	}

	

	void  RenderEngine::start() {


		while (!GlfwWindowShouldClose(window))
		{
			GlClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			GlClear(GL_COLOR_BUFFER_BIT);

			float timeValue = (float)GlfwGetTime();
			float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		
		
			GlBindVertexArray(VAO);
			shader->use();
			shader->setFloat("ourColor", 0.0f, greenValue, 0.0f, 1.0f);
			shader->setFloat("ourTime", timeValue);
			GlDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);

			GlfwSwapBuffers(window);
			GlfwPollEvents();
			inputSys->ProcessInput(window);
		}
		GlfwTerminate();
	}


NS_CY_END
