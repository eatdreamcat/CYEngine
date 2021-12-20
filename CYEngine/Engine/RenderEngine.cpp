
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

Vec3 cubePositions[] = {
	 Vec3(0.0f, 0.0f, 0.0f),
   Vec3(0.0f, 0.0f, 1.0f),
  Vec3(1.0f, 0.0f, 0.0f),
   Vec3(1.0f, 0.0f, 1.0f),
	Vec3(0.0f, 0.0f, -1.0f),
	 Vec3(-1.0f, 0.0f, -1.0f),
	  Vec3(1.0f, 0.0f, -1.0f),
	   Vec3(-1.0f, 0.0f, 1.0f),

		Vec3(-1.0f, 0.0f, 0.0f), 
 
};
const int CubeCount = sizeof(cubePositions)/sizeof(cubePositions[0]);


#pragma endregion


unsigned int VAO;
using namespace std;
Material* material;
GlTexture* glTexture;
GlTexture* glTextureLand;
Camera* camera;
DirectionalLight* directionalLight;
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


	auto diffuseTexture = new GlTexture(R"(../Resources/container2.png)", GL_RGBA, GL_RGBA);
	diffuseTexture->genTextureBuffer(GlTexture::DIFFUSE, GL_TEXTURE_2D);

	auto specularTexture = new GlTexture(R"(../Resources/container2_specular.png)", GL_RGBA, GL_RGBA);
	specularTexture->genTextureBuffer(GlTexture::SPECULAR, GL_TEXTURE_2D);

	auto emissionTexture = new GlTexture(R"(../Resources/bili.jpg)", GL_RGB, GL_RGB);
	emissionTexture->genTextureBuffer(GlTexture::EMISSION, GL_TEXTURE_2D);


	float ambient[3]{ 0.7f,0.7f,0.7f };
	material = new Material(new Shader(R"(../Engine/StandarShader.vert)", R"(../Engine/StandarShader.frag)"), glTexture, diffuseTexture, ambient, specularTexture, emissionTexture, 32);

	// 设置model读取格式
	GlVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	GlEnableVertexAttribArray(0);

	GlVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	GlEnableVertexAttribArray(1);

	GlVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	GlEnableVertexAttribArray(2);

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

	directionalLight = new DirectionalLight(Vec3(-45, 0,0), Vec3(0.1, 0.1, 0.1), Vec3(0.2, 0.2, 0.2), Vec3(1, 1, 1));

	auto pointLight = {
		new PointLight(Vec3(-12.0f, 10.0f, 0.0f), 1.0f, 0.09f, 0.032f, Vec3(1.0f, 1.0f, 0.0f)),
		new PointLight(Vec3(10.0f, -10.0f, 0.0f), 1.0f, 0.09f, 0.032f, Vec3(0.0f, 1.0f, 1.0f)),
		new PointLight(Vec3(-12.0f, 10.0f, 0.0f), 1.0f, 0.09f, 0.032f, Vec3(0.0f, 1.0f, 0.0f)),
		new PointLight(Vec3(10.0f, -10.0f, 10.0f), 1.0f, 0.09f, 0.032f, Vec3(1.0f, 0.0f, 0.0f)),
		new PointLight(Vec3(-12.0f, -10.0f, 0.0f), 1.0f, 0.09f, 0.032f, Vec3(0.0f, 1.0f, 2.0f)),
		new PointLight(Vec3(-10.0f, 10.0f, 0.0f), 1.0f, 0.09f, 0.032f, Vec3(1.0f, 0.0f, 2.0f)),
	};

	auto spotLight = {
		new SpotLight(Vec3(0.0f, -3.0f, 0.0f), Vec3(-90, 0, 0),5.0f, 15.0f, 1.0f, 0.09f, 0.032f, Vec3(5.0f, 5.0f, 5.0f)),

		new SpotLight(Vec3(0.0f, -2.0f, 0.0f), Vec3(-80, 0, 0),5.0f, 15.0f, 1.0f, 0.09f, 0.032f, Vec3(5.0f, 0.0f, 5.0f)),

		new SpotLight(Vec3(1.0f, -4.0f, 0.0f), Vec3(-70, 0, 0),5.0f, 15.0f, 1.0f, 0.09f, 0.032f, Vec3(5.0f, 5.0f, 0.0f)),
		
	};
	material->_shader->define("POINT_LIGHT_COUNT", std::to_string(pointLight.size()));
	material->_shader->define("SPOT_LIGHT_COUNT", std::to_string(spotLight.size()));
	material->_shader->compile();
	while (!GlfwWindowShouldClose(window))
	{

		InputSystem::GetInstance()->ProcessInput();


		GlClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		GlClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		float timeValue = (float)GlfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		material->_shader->use();
	
		Matrix4x4 viewMat;
		viewMat = camera->getViewMatrix();
		material->_shader->setMatrix4x4("view", 16, GL_FALSE, viewMat.m);
		material->_shader->setMatrix4x4("projection", 16, GL_FALSE, proMat.m);
		material->_shader->setFloat("cameraPos", camera->getPosition().x, camera->getPosition().y, camera->getPosition().z);
		material->_shader->setFloat("objColor", 1.0f, 1.0f, 1.0f);
		material->_shader->setFloat("ambientColor", 0.2f, 0.2f, 0.2f);
		material->setLightFactor();

		// directional light
		material->_shader->setFloat("directionalLight.direction", directionalLight->getDirection().x, directionalLight->getDirection().y, directionalLight->getDirection().z);
		material->_shader->setFloat("directionalLight.diffuse", directionalLight->getDiffuse().x, directionalLight->getDiffuse().y, directionalLight->getDiffuse().z);
		material->_shader->setFloat("directionalLight.ambient", directionalLight->getAmbient().x, directionalLight->getAmbient().y, directionalLight->getAmbient().z);
		material->_shader->setFloat("directionalLight.specular", directionalLight->getSpecular().x, directionalLight->getSpecular().y, directionalLight->getSpecular().z);
		int i = 0;
		
		for (auto light = spotLight.begin(); light != spotLight.end(); ++light) {
			
			material->_shader->setFloat(string("spotLights") + string("[" + to_string(i) + "]") + string(".direction"), (*light)->getDirection().x, (*light)->getDirection().y, (*light)->getDirection().z);
			material->_shader->setFloat(string("spotLights") + string("["+to_string(i)+"]") + string(".diffuse"), (*light)->getDiffuse().x, (*light)->getDiffuse().y, (*light)->getDiffuse().z);
			material->_shader->setFloat(string("spotLights") + string("[" + to_string(i) + "]") + string(".ambient"), (*light)->getAmbient().x, (*light)->getAmbient().y, (*light)->getAmbient().z);
			material->_shader->setFloat(string("spotLights") + string("[" + to_string(i) + "]") + string(".specular"), (*light)->getSpecular().x, (*light)->getSpecular().y, (*light)->getSpecular().z);

			material->_shader->setFloat(string("spotLights") + string("[" + to_string(i) + "]") + string(".position"), (*light)->getPosition().x, (*light)->getPosition().y, (*light)->getPosition().z);
			material->_shader->setFloat(string("spotLights") + string("[" + to_string(i) + "]") + string(".cosInner"), (*light)->getCosInner());
			material->_shader->setFloat(string("spotLights") + string("[" + to_string(i) + "]") + string(".cosOutter"), (*light)->getCosOutter());

			material->_shader->setFloat(string("spotLights") + string("[" + to_string(i) + "]") + string(".constant"), (*light)->getConstant());
			material->_shader->setFloat(string("spotLights") + string("[" + to_string(i) + "]") + string(".linear"), (*light)->getLinear());
			material->_shader->setFloat(string("spotLights") + string("[" + to_string(i) + "]") + string(".quadratic"), (*light)->getQuadratic());
			++i;
		}
		
		i = 0;
		for (auto light = pointLight.begin(); light != pointLight.end(); ++light) {
			material->_shader->setFloat(string("pointLights") + string("[" + to_string(i) + "]") + string(".diffuse"), (*light)->getDiffuse().x, (*light)->getDiffuse().y, (*light)->getDiffuse().z);
			material->_shader->setFloat(string("pointLights") + string("[" + to_string(i) + "]") + string(".ambient"), (*light)->getAmbient().x, (*light)->getAmbient().y, (*light)->getAmbient().z);
			material->_shader->setFloat(string("pointLights") + string("[" + to_string(i) + "]") + string(".specular"), (*light)->getSpecular().x, (*light)->getSpecular().y, (*light)->getSpecular().z);

			material->_shader->setFloat(string("pointLights") + string("[" + to_string(i) + "]") + string(".position"), (*light)->getPosition().x, (*light)->getPosition().y, (*light)->getPosition().z);
			material->_shader->setFloat(string("pointLights") + string("[" + to_string(i) + "]") + string(".constant"), (*light)->getConstant());
			material->_shader->setFloat(string("pointLights") + string("[" + to_string(i) + "]") + string(".linear"), (*light)->getLinear());
			material->_shader->setFloat(string("pointLights") + string("[" + to_string(i) + "]") + string(".quadratic"), (*light)->getQuadratic());
			++i;
		}

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



