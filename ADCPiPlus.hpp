#include"RPi_i2c.hpp"

class ADCPiPlus : RPi_i2c
{
  char const adctx[] = {0x01,0x80,0x00};
  char const adcrx[3];
  uint32_t spi_speed = static_cast<int>(2.5e6);
  double adcrefvoltage = 3.3;
  void modeset(const int channel,const int mode);
public:
  ADCPiPlus(const int address);
  double read(const int channel,const int mode);
};
