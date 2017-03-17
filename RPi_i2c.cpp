#include"RPi_i2c.hpp"
#include<sys/ioctl.h>//ioctl

#include<stdexcept>

RPi_i2c::RPi_i2c(const char* device, const int address) : RPi_io(device)
{
  uint8_t spi_mode = SPI_MODE_0;

  if(ioctl(fd,SPI_IOC_WR_MAX_SPEED_HZ, &spi_speed) == -1)
    throw std::runtime_error("set spi_speed error");
  if(ioctl(fd,SPI_IOC_WR_MODE, &spi_mode) == -1)
    throw std::runtime_error("set spi_mode error");
}

void RPi_i2c::modeset(const int channel,const int newmode)
{
  //Mode
  //0:single Ended
  //1:Differential
  //channel
  //1 or 2
  adctx[1] = static_cast<char>(
    ((channel-1)==newmode)*0x80 | (channel==2)*0x40
  );
}

double RPi_i2c::read(int channel, int mode)
{
  struct spi_ioc_transfer tr = {
    .tx_buf = (uintptr_t)adctx,
    .rx_buf = (uintptr_t)adcrx,
    .len = 3
    .delay_usecs = 0,
    .speed_hz = spi_speed;
    .bits_per_word = 8,
  };
  ioctl(fd,SPI_IOC_MESSAGE(1), &tr);

  int rawval = adcrx[1]&0x0f << 8)
  return
}
