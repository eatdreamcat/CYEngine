#version 330 core
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

struct Material {
	sampler2D diffuse;
	sampler2D specular;
	sampler2D emission;
	int shininess;
};


struct SpotLight {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec3 position;
	vec3 direction;
	float cosInner;
	float cosOutter;
    float constant;
   float linear;
   float quadratic;
};



#ifdef SPOT_LIGHT_COUNT
	uniform SpotLight spotLights[SPOT_LIGHT_COUNT];
#endif


struct PointLight {
   vec3 ambient;
   vec3 diffuse;
   vec3 specular;
   vec3 position;
   float constant;
   float linear;
   float quadratic;
   
};


#ifdef POINT_LIGHT_COUNT
	uniform PointLight pointLights[POINT_LIGHT_COUNT];
#endif

struct DirectionalLight {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec3 direction;
};

uniform Material material;

uniform DirectionalLight directionalLight;


uniform sampler2D ourTexture;
uniform vec3 objColor;
uniform vec3 ambientColor;
uniform vec3 cameraPos;

float CalDiffIntensity(vec3 lightDir, vec3 normal) {
    
    return max(dot(-lightDir, normal), 0);
}

float CalSpecularAmount(vec3 lightDir, vec3 normal, vec3 viewDir, float shininess) {

   if (max(dot(-lightDir, normal), 0) <= 0) {
		return 0;
   }
   // bling phong model
   vec3 dirHalfWay = normalize(-lightDir + viewDir);
   return pow(max(dot(viewDir,dirHalfWay), 0), shininess);
}

vec3 CalDirectionalLight(DirectionalLight light, Material material, vec3 normal, vec3 viewDir) {
   

	// diffuse
	vec3 diffuse = CalDiffIntensity(light.direction, normal) * light.diffuse * texture(material.diffuse, TexCoord).rgb ;

	//ambient
	vec3 ambient =  light.ambient * texture(material.diffuse, TexCoord).rgb * ambientColor;

	//specular
	vec3 specular = CalSpecularAmount(light.direction, normal, viewDir, material.shininess) * light.specular * texture(material.specular, TexCoord).rgb ; 

	return ( diffuse + ambient + specular ) * objColor;
}


vec3 CalSpotLight(SpotLight light, Material material, vec3 normal, vec3 viewDir) {
    vec3 result;

	vec3 lightDir = normalize(FragPos-light.position);
	float cosTheta = dot(lightDir, -light.direction);

	float spotAmount = clamp((cosTheta - light.cosOutter) / (light.cosInner - light.cosOutter) ,0.0,1.0);
	if (max(dot(-lightDir, normal), 0) <= 0) {
		spotAmount =  0;
   }

	vec3 diffuse = CalDiffIntensity(lightDir, normal) * light.diffuse * texture(material.diffuse, TexCoord).rgb;

	vec3 specular = CalSpecularAmount(lightDir, normal, viewDir, material.shininess) * light.specular * texture(material.specular, TexCoord).rgb;

	vec3 ambient = light.ambient * texture(material.diffuse, TexCoord).rgb * ambientColor;;

	float dist = length(light.position - FragPos);
	float attenuation = 1.0 / (light.constant + light.linear * dist + 
                 light.quadratic * (dist * dist)); 

	return ( diffuse + ambient + specular )*objColor*spotAmount*attenuation ;
}

vec3 CalPointLight(PointLight light, Material material, vec3 normal, vec3 viewDir) {
   

   
	vec3 lightDir = normalize(FragPos-light.position);

	
	vec3 diffuse = CalDiffIntensity(lightDir, normal) * light.diffuse * texture(material.diffuse, TexCoord).rgb;

	vec3 specular = CalSpecularAmount(lightDir, normal, viewDir, material.shininess) * light.specular * texture(material.specular, TexCoord).rgb;

	vec3 ambient = light.ambient * texture(material.diffuse, TexCoord).rgb * ambientColor;


	float dist = length(light.position - FragPos);
	float attenuation = 1.0 / (light.constant + light.linear * dist + 
                 light.quadratic * (dist * dist));    

    


	return (diffuse + specular + ambient)*objColor*attenuation;
}


out vec4 FragColor;
void main() {
   
    vec3 finalResult = vec3(0,0,0);
	vec3 uNormal = normalize(Normal);
	vec3 dirToCamera = normalize(cameraPos - FragPos);

	finalResult += CalDirectionalLight(directionalLight, material, uNormal, dirToCamera);
	
	#ifdef  SPOT_LIGHT_COUNT
		for(int i = 0;i < SPOT_LIGHT_COUNT; ++i) {
		   finalResult += CalSpotLight(spotLights[i], material, uNormal, dirToCamera);
	   }
	#endif
	
	#ifdef POINT_LIGHT_COUNT
		for (int i = 0; i < POINT_LIGHT_COUNT; ++i) {
		    finalResult += CalPointLight(pointLights[i], material, uNormal, dirToCamera);
	    }
	#endif
	
	FragColor = vec4(finalResult, 1.0);
}
