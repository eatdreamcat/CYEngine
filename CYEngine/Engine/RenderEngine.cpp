
#include "RenderEngine.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#pragma region ModelData
float vertices[] = {
	// positions          // normals           // texture coords
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
};

const int CubeCount = 9;
Vec3 cubePositions[] = {
  Vec3(0.0f,  0.0f,  0.0f),
  Vec3(1.0f, 0.0f, 0.0f),
 Vec3(0.0f, 0.0f, 1.0f),

  Vec3(1.0f,  0.0f,  1.0f),
  Vec3(-1.0f, 0.0f, 0.0f),
 Vec3(0.0f, 0.0f, -1.0f),

 Vec3(-1.0f,  0.0f,  -1.0f),
  Vec3(-1.0f, 0.0f, 1.0f),
 Vec3(1.0f, 0.0f, -1.0f),
};
#pragma endregion


unsigned int VAO;
using namespace std;
Material* material;
GlTexture* glTexture;
GlTexture* glTextureLand;
Camera* camera;
DirectionalLight* directionalLight;
PointLight* pointLight;
SpotLight* spotLight;
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
	InputSystem::GetInstance()->bindWindow(window);
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

	// 设置model
	GlGenVertexArrays(1, &VAO);
	GlBindVertexArray(VAO);

	// 传入顶点
	unsigned int VBO;
	GlGenBuffers(1, &VBO);
	GlBindBuffer(GL_ARRAY_BUFFER, VBO);
	GlBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	auto diffuse = new GlTexture(R"(../Resources/container2.png)", GL_RGBA, GL_RGBA);
	diffuse->genTextureBuffer(GlTexture::DIFFUSE, GL_TEXTURE_2D);

	auto specular = new GlTexture(R"(../Resources/container2_specular.png)", GL_RGBA, GL_RGBA);
	specular->genTextureBuffer(GlTexture::SPECULAR, GL_TEXTURE_2D);

	auto emission = new GlTexture(R"(../Resources/matrix.jpg)", GL_RGB, GL_RGB);
	emission->genTextureBuffer(GlTexture::EMISSION, GL_TEXTURE_2D);


	float ambient[3]{ 0.7f,0.7f,0.7f };
	material = new Material(new Shader(R"(../Engine/TestVertexShader.vert)", R"(../Engine/TestFragmentShader.frag)"), glTexture, diffuse, ambient, specular, emission, 64);

	// 设置model读取格式
	GlVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	GlEnableVertexAttribArray(8);

	GlVertexAttribPointer(9, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	GlEnableVertexAttribArray(9);

	GlVertexAttribPointer(10, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	GlEnableVertexAttribArray(10);

	return true;
}



void  RenderEngine::start() {




	camera = new Camera(Vec3(0, 0, 3), 0.0f, 180.0f, 0.0f, Vec3::UNIT_Y);
	InputSystem::GetInstance()->camera = camera;
	float rotation = 0;

	Matrix4x4 proMat;
	proMat.createPerspective(45, 800 / 600, 0.1f, 100.0f, &proMat);




	GlEnable(GL_DEPTH_TEST);
	GlfwCursorEnable(window, false);


	// light

	directionalLight = new DirectionalLight(Vec3(10.0f, 10.5f, 5.31f),  Vec3(45, 45,0), Vec3(1.0f,0.0f,0.0f));

	pointLight = new PointLight(Vec3(3.0f, 4.0f, 0.0f), 1.0f, 0.09f, 0.032f, Vec3(2.0f, 2.0f, 2.0f));

	spotLight = new SpotLight(Vec3(-0.25f, 3.0f, 1.2f), Vec3(90, 0, 0), 10.0f, 10.0f, Vec3(2.0f, 2.0f, 2.0f));
	while (!GlfwWindowShouldClose(window))
	{

		InputSystem::GetInstance()->ProcessInput();


		GlClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		GlClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		float timeValue = (float)GlfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		material->_shader->use();
		material->_shader->setFloat("ourColor", 0.0f, greenValue, 0.0f, 1.0f);
		material->_shader->setFloat("ourTime", timeValue);
		material->_shader->setFloat("randomNum", (float)(rand() / RAND_MAX) - 0.5f);
		material->_shader->setFloat("center", 0.5, 0.5);
		Matrix4x4 viewMat;
		viewMat = camera->getViewMatrix();
		material->_shader->setMatrix4x4("view", 16, GL_FALSE, viewMat.m);
		material->_shader->setMatrix4x4("projection", 16, GL_FALSE, proMat.m);

		material->_shader->setFloat("objColor", 1.0f, 1.0f, 1.0f);
		material->_shader->setFloat("ambientColor", 0.3f, 0.3f, 0.3f);
		material->_shader->setFloat("lightDir", directionalLight->getDirection().x, directionalLight->getDirection().y, directionalLight->getDirection().z);
		material->_shader->setFloat("lightColor", directionalLight->getColor().x, directionalLight->getColor().y, directionalLight->getColor().z);
		material->_shader->setFloat("cameraPos", camera->getPosition().x, camera->getPosition().y, camera->getPosition().z);

		material->_shader->setFloat("pointLightPos", pointLight->getPosition().x, pointLight->getPosition().y, pointLight->getPosition().z);
		material->_shader->setFloat("pointColor", pointLight->getColor().x, pointLight->getColor().y, pointLight->getColor().z);

		material->_shader->setFloat("lightPoint.constant", pointLight->getConstant());
		material->_shader->setFloat("lightPoint.linear", pointLight->getLinear());
		material->_shader->setFloat("lightPoint.quadratic", pointLight->getQuadratic());

		material->_shader->setFloat("spotLight.color", spotLight->getColor().x, spotLight->getColor().y, spotLight->getColor().z);
		material->_shader->setFloat("spotLight.position", spotLight->getPosition().x, spotLight->getPosition().y, spotLight->getPosition().z);
		material->_shader->setFloat("spotLight.direction", spotLight->getDirection().x, spotLight->getDirection().y, spotLight->getDirection().z);
		material->_shader->setFloat("spotLight.cosInner", spotLight->getCosInner());
		material->_shader->setFloat("spotLight.cosOutter", spotLight->getCosOutter());


		material->setLightFactor();
		//rotation += 0.01;

		for (unsigned int i = 0; i < CubeCount; i++)
		{
			Matrix4x4 modelMat;
			Matrix4x4 rotationModel;
			modelMat.createRotation(Vec3::ONE, rotation, &rotationModel);
			modelMat.createTranslation(cubePositions[i], &modelMat);
			modelMat.multiply(rotationModel);


			material->_shader->setMatrix4x4("model", 16, GL_FALSE, modelMat.m);
			// 选择model
			GlBindVertexArray(VAO);

			// draw call
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}



		// clear up and prepare for next frame
		GlfwSwapBuffers(window);
		GlfwPollEvents();

	}
	GlfwTerminate();
	delete		material;
	material = nullptr;
	delete glTexture;
	glTexture = nullptr;

	delete glTextureLand;
	glTextureLand = nullptr;
	InputSystem::ReleaseInstance();
}



