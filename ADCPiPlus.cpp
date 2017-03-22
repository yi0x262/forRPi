#include"ADCPiPlus.hpp"

#include<fcntl.h>//ioctl
#include<cmath>//log2


ADCPiPlus::ADCPiPlus(const int address,const int channel,const int conversion,const int bit_rate,const int pga)
  : RPi_i2c("/dev/i2c-1",address)
{
  modeset(channel,conversion,bit_rate,pga);
}

void ADCPiPlus::modeset(const int channel,const int conversion,const int bit_rate,const int pga)
{
  //adctx[0]  : 1,channel,channel,conversion,bitrate,bitrate,pga,pga

  //pga       : 1,2,4,8
  //bit_rate  : 12,14,16,18
  //conversion: 0,1
  //channel   : 1,2,3,4
  adctx = static_cast<int>(std::log2(0x0f&pga))
        | ((bit_rate/2-6)&0x03 << 2)
        | ((conversion==1) << 4)
        | ((channel-1)&0x03 << 5)
        | 0x80;
  lsb = 0.001/(1 << bit_rate-11);
  gain = pga/2.;
}
double ADCPiPlus::read()
{
  int raw = -1;
  _write(&adctx);
  if(adctx&0x0c == 0x0c)//bitrate:18
  {
    _read(adcrx);
    raw = ((adcrx[0]&0x03)<<16) | (adcrx[1] << 8) | adcrx[2];
    raw &= (raw>>17) ? 0:~(1<<17);
  }
  else
  {
    _read(&adcrx[1]);
    switch(adctx&0x0c >> 2)
    {
      case 0://bitrate:12
        raw = ((adcrx[1]&0x0f) << 8) | adcrx[2];
        raw &= (raw>>11) ? 0:~(1<<11);
        break;
      case 1://bitrate:14
        raw = ((adcrx[1]&0x3f) << 8) | adcrx[2];
        raw &= (raw>>13) ? 0:~(1<<13);
        break;
      case 2://bitrate:16
        raw = (adcrx[1] << 8) | adcrx[2];
        raw &= (raw>>15) ? 0:~(1<<15);
        break;
      default:
        break;
    }
  }

  return raw*(lsb/gain) * 2.471;//magic number
}
