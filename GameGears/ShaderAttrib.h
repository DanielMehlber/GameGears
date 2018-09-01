#pragma once
class ShaderAttrib
{
public:
	ShaderAttrib(int location, const char* name);
	~ShaderAttrib();
	int getLocation();
	const char* getName();

private:
	int location;
	const char* name;
};

