
#include "RenderEngine.h"
#include<iostream>
#include "Shader.h"
#include "OpenGLMacros.h"
//#include <stb_image.h>
#include"GlTexture.h"
#include"Camera.h"


float vertices[] = {
	 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

unsigned int indices[] = {
	0,1,2,
	2,3,0
};



unsigned int VAO;
using namespace std;
Shader* shader;
GlTexture* glTexture;
Shader* shaderLand;
GlTexture* glTextureLand;
Camera* camera;
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

		/*unsigned int EBO;
		GlGenBuffers(1, &EBO);
		GlBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		GlBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

		/*unsigned int texture;
		GlGenTextures(1, &texture);
		GlBindTexture(GL_TEXTURE0, texture);
		int tex_width, tex_height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(R"(../Resources/TEST.jpg)", &tex_width, &tex_height, &nrChannels, 0);
		if (data)
		{
			GlTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width, tex_height, GL_RGB, GL_UNSIGNED_BYTE, data);
			GlTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			GlTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);*/
		glTexture = new GlTexture(R"(../Resources/TEST.jpg)");
		glTexture->genTextureBuffer(GL_TEXTURE0, GL_TEXTURE_2D);
		

		glTextureLand = new GlTexture(R"(../Resources/land.jpg)");
		glTextureLand->genTextureBuffer(GL_TEXTURE1, GL_TEXTURE_2D);
		glTexture->setTextureWrapMode(GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
		glTextureLand->setTextureWrapMode(GL_REPEAT, GL_REPEAT);

		/**
		* CREATE SHADER
		*/
		shader = new Shader(R"(../Engine/TestVertexShader.txt)", R"(../Engine/TestFragmentShader.txt)");


		
		GlVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		GlEnableVertexAttribArray(8);

		GlVertexAttribPointer(9, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
		GlEnableVertexAttribArray(9);

		/*GlVertexAttribPointer(10, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		GlEnableVertexAttribArray(10);*/

		return true;
	}

	

	void  RenderEngine::start() {


		
		/*Vec3 vec3; 
		Vec3 move(2.0f, 5.5f, 0.0f);
		vec3.translate(move);
		cout << vec3.x << vec3.y << vec3.z << endl;*/
		camera = new Camera(Vec3(0, 0, 3), Vec3(0,1,0), Vec3::UNIT_Y);
		float rotation = 0;
		Matrix4x4 viewMat;
		viewMat = camera->getViewMatrix();
		Matrix4x4 proMat;
		proMat.createPerspective(45, 800 / 600, 0.1f, 100.0f,&proMat);

		Vec3 cubePositions[] = {
  Vec3(0.0f,  0.0f,  0.0f),
  Vec3(2.0f,  5.0f, -15.0f),
  Vec3(-1.5f, -2.2f, -2.5f),
  Vec3(-3.8f, -2.0f, -12.3f),
 Vec3(2.4f, -0.4f, -3.5f),
 Vec3(-1.7f,  3.0f, -7.5f),
  Vec3(1.3f, -2.0f, -2.5f),
 Vec3(1.5f,  2.0f, -2.5f),
 Vec3(1.5f,  0.2f, -1.5f),
 Vec3(-1.3f,  1.0f, -1.5f)
		};


		GlEnable(GL_DEPTH_TEST);
		while (!GlfwWindowShouldClose(window))
		{
			GlClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			GlClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			GlBindVertexArray(VAO); 
			float timeValue = (float)GlfwGetTime();
			float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
			shader->use();
			shader->setFloat("ourColor", 0.0f, greenValue, 0.0f, 1.0f);
			shader->setFloat("ourTime", timeValue);
			shader->setFloat("randomNum", (float)(rand() / RAND_MAX) - 0.5f);
			shader->setFloat("center", 0.5, 0.5);
			shader->setMatrix4x4("view", 1, GL_FALSE, viewMat.m);
			shader->setMatrix4x4("projection", 1, GL_FALSE, proMat.m);
			
			rotation+=0.01;

			for (unsigned int i = 0; i < 10; i++)
			{
				Matrix4x4 modelMat;
				Matrix4x4 rotationModel;
				modelMat.createRotation(Vec3::ONE, rotation + i*10, &rotationModel);
				modelMat.createTranslation(cubePositions[i], &modelMat);
				modelMat.multiply(rotationModel);
				

				shader->setMatrix4x4("model", 1, GL_FALSE, modelMat.m);

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
			
			
			

			GlfwSwapBuffers(window);
			GlfwPollEvents();
			inputSys->ProcessInput(window);
		}
		GlfwTerminate();
		delete		shader;
		shader = nullptr;
		delete glTexture;
		glTexture = nullptr;
	}



