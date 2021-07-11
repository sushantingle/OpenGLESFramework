#ifndef OPENGLESFRAMEWORK_SHADER_H
#define OPENGLESFRAMEWORK_SHADER_H

#include "../GLCore.h"

namespace GLCore::Utils {

	class Shader
	{
	public:
		virtual ~Shader();
		Shader() = default;
		GLuint GetRendererID() { return m_RendererID; }
		virtual void Bind() { glUseProgram(m_RendererID); };
		static Shader* FromGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	protected:
	

		void LoadFromGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		
		GLuint CompileShader(GLenum type, const std::string& source);
	protected:
		GLuint m_RendererID = 0;
	};

}
#endif