#include"RPi_io.hpp"
#include<stdint.h>

class RPi_i2c::RPi_io
{
  int _read(char buffer[]);
  int _write(char buffer[]);
public:
  RPi_i2c(const char device[],const int address);
}
