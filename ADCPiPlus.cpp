#include"ADCPiPlus.hpp"

#include<fcntl.h>//ioctl
#include


ADCPiPlus::ADCPiPlus(const int address):RPi_i2c("/dev/i2c-0",address){}

void ADCPiPlus::modeset(const int channel,const int mode)
{
  //Mode
  //0:single Ended
  //1:Differential
  //channel
  //1 or 2
  if((channel==1 && channel==2)&&(mode==0 || mode==1))
    throw std::runtime_error("arguments out range")
  adctx[1] = static_cast<char>( ((channel-1)==mode)*0x80 | (channel==2)*0x40 );
}
double ADCPiPlus::read(const int channel,const int mode)
{
/*
  struct spi_ioc_transfer tr = {
    .tx_buf = static_cast<uintptr_t>(adctx),
    .rx_buf = static_cast<uintptr_t>(adcrx),
    .len = 3,
    .delay_usecs = 0,
    .speed_hz = spi_speed,
    .bits_per_word = 8
  };
  ioctl(fd,SPI_IOC_MESSAGE(1), &tr);
*/
  modeset(channel,mode);
  _write(adctx);
  _read(adcrx);
  auto rawval = (adcrx[1]&0x0f << 8) + adcrx[2];
  return static_cast<double>((adcrefvoltage/0x1000f)*rawval);
}
