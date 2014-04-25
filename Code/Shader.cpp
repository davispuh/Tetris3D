#include "stdafx.hpp"

Shader::~Shader()
{
}

void Shader::setBlockBinding(const std::string &Name, unsigned int BindingPoint)
{
	if (m_shaderProgram)
	{
		unsigned int BlockIndex = getParamBlockIndex(Name);
		if (BlockIndex != GL_INVALID_INDEX)
		{
			glUniformBlockBinding(m_shaderProgram, BlockIndex, BindingPoint);
		};
	};
};

unsigned int Shader::getParamBlockIndex(const std::string &Name)
{
	IndexTable::const_iterator it = Indexes.find(Name);
	if (it != Indexes.end())
	{
		return it->second;
	}
	else
	{
		GLuint Index = glGetProgramResourceIndex(m_shaderProgram, GL_UNIFORM_BLOCK, Name.c_str());
		if (Index != GL_INVALID_INDEX)
		{
			Indexes.insert(std::make_pair(Name, Index));
		};
		return Index;
	}
};
