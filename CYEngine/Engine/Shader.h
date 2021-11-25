#pragma once
#include<string>
#include "CObject.h"
#include"EngineMacros.h"
NS_CY_BEGIN
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
    void use();
    void setBool(const string& name, bool value) const;
    void setInt(const string& name, int value) const;
    void setFloat(const string& name, float value) const;
private:
    const char* vertexSource;
    const char* fragmentSource;
    string vertexString;
    string fragmentString;
    bool compile();
};
NS_CY_END

