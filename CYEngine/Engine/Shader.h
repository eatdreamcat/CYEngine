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
    /*指定当前要用的shader程序*/
    void use();
    /*给shader程序传送 bool*/
    void setBool(const string& name, bool value) const;
    /*给shader程序传送 1 int 分量 uniform*/
    void setInt(const string& name, int value) const;
    /*给shader程序传送 n int 数组 uniform*/
    void setIntArray(const string& name, int count, const int* array, bool isArray = false) const;
    /*给shader程序传送 2 int 分量 uniform*/
    void setInt(const string& name, int value0,  int value1) const;
    /*给shader程序传送 3 int 分量 uniform*/
    void setInt(const string& name, int value0, int value1, int value2) const;
    /*给shader程序传送 4 int 分量 uniform*/
    void setInt(const string& name, int value0, int value1, int value2, int value3) const;
    /*给shader程序传送 1 float 分量 uniform*/
    void setFloat(const string& name, float value) const;
    /*给shader程序传送 n float 数组 uniform*/
    void setFloatArray(const string& name, int count, const float* array, bool isArray = false) const;
    /*给shader程序传送 2 float 分量 uniform*/
    void setFloat(const string& name, float value0, float value1) const;
    /*给shader程序传送 3 float 分量 uniform*/
    void setFloat(const string& name, float value0, float value1, float value2) const;
    /*给shader程序传送 4 float 分量 uniform*/
    void setFloat(const string& name, float value0, float value1, float value2, float value3) const;
    /*设置一个4x4矩阵*/
    void setMatrix4x4(const string& name, int count, GLboolean transpose, const GLfloat* value, bool isArray = false) const;
    /*设置贴图*/
    void setTexture(const string& name, int textureSlot) const;
private:
    const char* vertexSource;
    const char* fragmentSource;
    string vertexString;
    string fragmentString;
    bool compile();
    bool checkCompileResult(GLuint shader, GLenum pname);
};


