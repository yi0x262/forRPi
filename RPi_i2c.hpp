#include"RPi_io.hpp"
#include<stdint.h>

union RPi_i2c_rx
{
  char ch[3];
  
}

class RPi_i2c:RPi_io
{
  uint32_t spi_speed = static_cast<int>(2.5e6);
  uint32_t adctx[] = {0x01,0x80,0x00};
  char adcrx[3];
public:
  RPi_i2c(const char* device,const int address);
  double read(char* buffer);
}
