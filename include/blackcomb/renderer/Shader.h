#ifndef CRAFTCLONE_SHADER_H
#define CRAFTCLONE_SHADER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <glad/glad.h>

const std::unordered_map<GLuint, std::string> ShaderNames = {
    {GL_VERTEX_SHADER, "vertex shader"},
    {GL_FRAGMENT_SHADER, "fragment shader"},
    {GL_GEOMETRY_SHADER, "geometry shader"},
    {GL_COMPUTE_SHADER, "compute shader"},
    {GL_TESS_CONTROL_SHADER, "tesselation control shader"},
    {GL_TESS_EVALUATION_SHADER, "tesselation evaluation shader"},
    {0, "shader"}
};

static std::string getShaderName(GLuint shaderType) {
    auto res = ShaderNames.find(shaderType);
    if (res != ShaderNames.end()) {
        return res->second;
    }
    return ShaderNames.at(0);
}

class Shader {
public:
    Shader(std::string vertexFilename, std::string fragmentFilename);
    void bind();
    static void unbind();
    void setUniformInt(const char* name, int val);
    void setUniformFloat(const char* name, float val);
    void setUniformDouble(const char* name, double val);
    void setUniformVecF(const char* name, std::vector<GLfloat> val);
    void setUniformVecF(const char* name, float val[], size_t size);
    void setUniformMat4F(const char* name, GLfloat* value, GLboolean transpose = GL_FALSE);
    GLuint program;
private:
    GLuint loadAndCompileShader(unsigned int shaderType, std::string filename);
    void reportCompileStatus(GLuint shaderType, GLuint shader);
    void reportLinkStatus(GLuint program);
};


#endif //CRAFTCLONE_SHADER_H