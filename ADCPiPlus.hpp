#include"RPi_i2c.hpp"

class ADCPiPlus : public RPi_i2c
{
  char adctx[3] = {(char)0x01,(char)0x80,(char)0x00};
  char adcrx[3];
  uint32_t spi_speed = static_cast<int>(2.5e6);
  double adcrefvoltage = 3.3;
  void modeset(const int channel,const int mode);
public:
  ADCPiPlus(int address);
  double read(const int channel,const int mode);
};
