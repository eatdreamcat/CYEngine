#pragma once
#include<string>
#include "CObject.h"
#include"EngineMacros.h"
#include "OpenGLMacros.h"

USING_STD;
class Shader :
    public CObject
{
public:
    unsigned int ID;
    Shader(const char* vertexPath, const char* fragmentPath);
    virtual ~Shader() {};
    
    const  char*const* GetVertexSource() { return &vertexSource; };
    const  char*const* GetFragmentSource() { return &fragmentSource; };
    /*ָ����ǰҪ�õ�shader����*/
    void use();
    /*��shader������ bool*/
    void setBool(const string& name, bool value) const;
    /*��shader������ 1 int ���� uniform*/
    void setInt(const string& name, int value) const;
    /*��shader������ n int ���� uniform*/
    void setIntArray(const string& name, int count, const int* array, bool isArray = false) const;
    /*��shader������ 2 int ���� uniform*/
    void setInt(const string& name, int value0,  int value1) const;
    /*��shader������ 3 int ���� uniform*/
    void setInt(const string& name, int value0, int value1, int value2) const;
    /*��shader������ 4 int ���� uniform*/
    void setInt(const string& name, int value0, int value1, int value2, int value3) const;
    /*��shader������ 1 float ���� uniform*/
    void setFloat(const string& name, float value) const;
    /*��shader������ n float ���� uniform*/
    void setFloatArray(const string& name, int count, const float* array, bool isArray = false) const;
    /*��shader������ 2 float ���� uniform*/
    void setFloat(const string& name, float value0, float value1) const;
    /*��shader������ 3 float ���� uniform*/
    void setFloat(const string& name, float value0, float value1, float value2) const;
    /*��shader������ 4 float ���� uniform*/
    void setFloat(const string& name, float value0, float value1, float value2, float value3) const;
    /*����һ��4x4����*/
    void setMatrix4x4(const string& name, int count, GLboolean transpose, const GLfloat* value, bool isArray = false) const;
    /*������ͼ*/
    void setTexture(const string& name, int textureSlot) const;
private:
    const char* vertexSource;
    const char* fragmentSource;
    string vertexString;
    string fragmentString;
    bool compile();
    bool checkCompileResult(GLuint shader, GLenum pname);
};


