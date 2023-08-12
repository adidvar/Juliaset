#ifndef SHADER_H
#define SHADER_H

const char* load_from_file(const char* name);

class Shader {
 public:
  Shader();
  void Use();

  unsigned int ID;
};

#endif
