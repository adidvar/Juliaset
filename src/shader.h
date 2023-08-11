#ifndef SHADER
#define SHADER

const char* load_from_file(const char* name);

class Shader {
public:
	Shader();
	void Use();
    unsigned int ID;
private:
};

#endif // !SHADER
