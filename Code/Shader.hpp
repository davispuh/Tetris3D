#pragma once

class Shader : public sf::Shader
{
protected:
	typedef std::map<std::string, unsigned int> IndexTable;
	IndexTable Indexes;
public:
	virtual ~Shader();
	void setBlockBinding(const std::string &Name, unsigned int BindingPoint);
	unsigned int getParamBlockIndex(const std::string &Name);
};
