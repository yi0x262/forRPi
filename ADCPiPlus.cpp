#include"ADCPiPlus.hpp"

ADCPiPlus::ADCPiPlus(const int address):RPi_i2c("/dev/i2c-0",address)
{
  uint8_t spi_mode = SPI_MODE_0;

  if(ioctl(fd,SPI_IOC_WR_MAX_SPEED_HZ, &spi_speed) == -1)
    throw std::runtime_error("set spi_speed error");

  if(ioctl(fd,SPI_IOC_WR_MODE, &spi_mode) == -1)
    throw std::runtime_error("set spi_mode error");
}

void ADCPiPlus::modeset(const int channel,const int mode)
{
  //Mode
  //0:single Ended
  //1:Differential
  //channel
  //1 or 2
  if((channel==1 && channel==2)&&(newmode==0 || newmode==1))
    throw std::runtime_error("arguments out range")
  adctx[1] = static_cast<char>( ((channel-1)==newmode)*0x80 | (channel==2)*0x40 );
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
  ::modeset(channel,mode);
  ::_write(adctx);
  ::_read(adcrx);
  auto rawval = (adcrx[1]&0x0f << 8) + adcrx[2];
  return static_cast<double>((adcrefvoltage/0x1000f)*rawval);
}
