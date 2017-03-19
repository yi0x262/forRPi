#include"RPi_i2c.hpp"
#include<sys/ioctl.h>//ioctl
#include<linux/i2c-dev.h>//read,write

#include<stdexcept>
using std::runtime_error;

RPi_i2c::RPi_i2c(const char device[], const int address) : RPi_io(device)
{
  if(ioctl(fd,I2C_SLAVE,address)<0)
    throw runtime_error("i2c address set error");
}

int RPi_i2c::_write(char buffer[]) const
{
  if((int ret = write(fd,buffer,strlen(buffer))) < 0)
    throw runtime_error("i2c write error");
  else return ret;
}

int RPi_i2c::_read(char buffer[]) const
{
  if((int ret = read(fd,buffer,sizeof(buffer))) < 0)
    throw runtime_error("i2c read error");
  else return ret;
}
