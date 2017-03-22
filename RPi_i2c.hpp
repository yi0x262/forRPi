#include"RPi_io.hpp"
#include<stdint.h>

class RPi_i2c:public RPi_io
{
protected:
  int _read(char buffer[])const;
  int _write(char buffer[])const;
public:
  RPi_i2c(const char device[],const int address);
};
