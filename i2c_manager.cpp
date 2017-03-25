#include"i2c_manager.hpp"
#include<sys/ioctl.h>//ioctl
#include<linux/i2c-dev.h>//read,write
#include<unistd.h>

#include<cerrno>
#include<system_error>

file i2c_manager::bus

i2c_manager::i2c_manager(const char device[], const int address)
{
  if(ioctl(fd,I2C_SLAVE,address)<0)
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
