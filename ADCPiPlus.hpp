#include"RPi_i2c.hpp"

class ADCPiPlus : public RPi_i2c
{
  double lsb = 1.;
  double gain = 0.;
  int wait_us = 0;

  char adctx = static_cast<char>(0x9c);
  char adcrx[4];
  void modeset(const int conversion,const int bit_rate,const int pga,const int waittime);
  void setchannel(const int channel);
public:
  ADCPiPlus(const int address,const int conversion,const int bit_rate,const int pga,const int wait_us);
  double read(const int channel);
};
