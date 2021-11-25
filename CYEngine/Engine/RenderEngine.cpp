
#include "RenderEngine.h"
#include<iostream>
#include"Shader.h"
#include "OpenGLMacros.h"
NS_CY_BEGIN
float vertices[] = {
-0.5f, -0.5f, 0.0f, 1.0f,0.0f,0.0f,//0
 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, //1
 0.0f,  0.5f, 0.0f, 0.0f,0.0f,1.0f, // 2
 //0.0f,  0.5f, 0.0f, // 2
 // 0.5f, -0.5f, 0.0f,  // 1
 0.8f,0.8f,0.0f  ,1.0f,1.0f,0.0f// 3
};

unsigned int indices[] = {
	0,1,2,
	2,1,3
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


		/**
		* CREATE SHADER
		*/
		shader = new Shader(R"(../Engine/TestVertexShader.txt)", R"(../Engine/TestFragmentShader.txt)");
		
		GlVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		GlEnableVertexAttribArray(8);

		GlVertexAttribPointer(9, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
		GlEnableVertexAttribArray(9);

		

		return true;
	}

	

	void  RenderEngine::start() {


		while (!GlfwWindowShouldClose(window))
		{
			GlClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			GlClear(GL_COLOR_BUFFER_BIT);

			float timeValue = (float)GlfwGetTime();
			float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
			int vertexColorLocation = GlGetUniformLocation(shader->ID, "ourColor");
		
			GlBindVertexArray(VAO);
			shader->use();
			GlUniform(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
			GlDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);

			GlfwSwapBuffers(window);
			GlfwPollEvents();
			inputSys->ProcessInput(window);
		}
		GlfwTerminate();
	}


NS_CY_END
