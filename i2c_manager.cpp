#include"i2c_manager.hpp"
#include<sys/ioctl.h>//ioctl
#include<linux/i2c-dev.h>//read,write
#include<unistd.h>

#include<cerrno>
#include<system_error>

int i2c_manager::i2c_descriptor = -1;

i2c_manager::i2c_manager(const char device[], const int address)
{
  if(i2c_descriptor < 0)//ugly
  {
    bus = file(device);
    i2c_descriptor = bus.get_descriptor();
  }
  if(ioctl(i2c_descriptor,I2C_SLAVE,address)<0)
  {
    throw std::system_error(errno,std::system_category());
  }
}

int write(char buf[])const
{
  return bus._write(buf);
}

int read(char writebuf[],char readbuf[],int readsize)const
{
  write(writebuf);
  return bus._read(readbuf,readsize);
}
