#version 330 core
out vec4 FragColor;
in vec4 vertexColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

struct Material {
    vec3 ambient;
	sampler2D diffuse;
	sampler2D specular;
	sampler2D emission;
	int shininess;
};


struct LightPoint {
   float constant;
   float linear;
   float quadratic;
};

struct SpotLight {
	vec3 color;
	vec3 position;
	vec3 direction;
	float cosInner;
	float cosOutter;
	
};

uniform LightPoint lightPoint;
uniform Material material;
uniform SpotLight spotLight;


uniform sampler2D ourTexture;
uniform float ourTime;
uniform float randomNum;
uniform vec2 center;
uniform vec3 objColor;
uniform vec3 ambientColor;
uniform vec3 lightColor; 
uniform vec3 cameraPos; 
uniform vec3 lightDir;

uniform vec3 pointColor; 
uniform vec3 pointLightPos;
void main() {
    float lightDistance = length(pointLightPos - FragPos);
    float attenuation = 1.0 / (lightPoint.constant + lightPoint.linear*lightDistance + lightPoint.quadratic* (lightDistance* lightDistance));
	
	
	vec3 pointLightDir = normalize(pointLightPos - FragPos);
	vec3 reflectVec = reflect(-pointLightDir, Normal);
	vec3 viewDir = normalize(cameraPos - FragPos);
	float specularAmount = pow(max(dot(reflectVec, viewDir),0), material.shininess);
	vec3 specular = texture(material.specular, TexCoord).rgb * specularAmount * pointColor;

	vec3 diffuse =  texture(material.diffuse, TexCoord).rgb * max(dot(pointLightDir, Normal), 0) * pointColor;
	vec3 ambient =  texture(material.diffuse, TexCoord).rgb * material.ambient * ambientColor;

	vec3 emission = texture(material.emission, TexCoord).rgb;

	float cosFragTheta = dot(normalize(FragPos - spotLight.position), -1* spotLight.direction);
	
	float spotRatio = max((cosFragTheta - spotLight.cosOutter) / (spotLight.cosInner - spotLight.cosOutter), 0);
	diffuse = diffuse +  texture(material.diffuse, TexCoord).rgb * max(dot( spotLight.direction, Normal), 0) *  spotLight.color * spotRatio ;
	reflectVec = reflect(-spotLight.direction, Normal);
    specularAmount = pow(max(dot(reflectVec, viewDir),0), material.shininess);
    specular = specular + texture(material.specular, TexCoord).rgb * specularAmount * spotLight.color * spotRatio;
	FragColor = vec4(objColor*(ambient + (diffuse + specular)*attenuation ), 1.0);

	
}
/*
void main()
{
    float offset_u = 0.25*( sin(3.14*TexCoord.y*1.5+ 4*ourTime) + 1 )/2;
	float width = 0.5;
	if (TexCoord.x<offset_u || TexCoord.x>offset_u+0.5) {
	    FragColor = vec4(0,0,0,0);
	}else {
	   FragColor = texture(ourTexture,vec2(TexCoord.x+offset_u,TexCoord.y)) * vec4((sin(3.14*TexCoord.x + ourTime)+1)/2,(cos(3.14 * ourTime)+1)/2,(sin(3.14 * TexCoord.y- ourTime)+1)/2,1);
	}
	
}

void main()
{
  float len = sqrt((TexCoord.x-center.x)*(TexCoord.x-center.y) +(TexCoord.y-center.x)*(TexCoord.y-center.y) );
  float offset = sin(len + ourTime*2)*randomNum*len;

  float u=TexCoord.x+(TexCoord.x -center.x)/len*offset;
  float v=TexCoord.y+(center.y-TexCoord.y)/len*offset;
  //u = max(0, min(u,1));
  //v = max(0, min(v,1));
  FragColor = texture(ourTexture,vec2(u,v));
  
}*/