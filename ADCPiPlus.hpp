#include"RPi_i2c.hpp"

class ADCPiPlus : public RPi_i2c
{
  double lsb = 0.;
  double gain = 0.;
  char adctx = static_cast<char>(0x9c);
  char adcrx[4];
  void modeset(const int channel,const int conversion,const int bit_rate,const int pga);
public:
  ADCPiPlus(int address);
  double read(const int channel,const int mode);
};
