#include"RPi_i2c.hpp"
#include<stdint.h>

union readbuffer2
{
  uint16_t num;
  char buf[2];
}

class L3DG20 : private RPi_i2c
{
  readbuffer2 buf;
  int read_xyz(const int reg);
public:
  L3DG20(void);
  int read_x(void);
  int read_y(void);
  int read_z(void);
}
