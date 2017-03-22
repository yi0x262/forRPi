#include"RPi_i2c.hpp"
#include<sys/ioctl.h>//ioctl
#include<linux/i2c-dev.h>//read,write
#include<unistd.h>

#include<stdexcept>
using std::runtime_error;
#include<errno.h>
#include<stdio.h>//perror
#include<string.h>//strlen

RPi_i2c::RPi_i2c(const char device[], const int address) : RPi_io(device)
{
  if(ioctl(fd,I2C_SLAVE,address)<0)
    printf("fd=%d\terrno=:%d,\t%s\n",fd,errno,strerror(errno));
    throw runtime_error("i2c address set error : unable access");
}

int RPi_i2c::_write(char buffer[]) const
{
  int ret;
  if((ret = write(fd,buffer,strlen(buffer))) < 0)
    printf("fd=%d\terrno=:%d,\t%s\n",fd,errno,strerror(errno));
    throw runtime_error("i2c write error");
  return ret;
}

int RPi_i2c::_read(char buffer[]) const
{
  int ret;
  if((ret = read(fd,buffer,sizeof(buffer))) < 0)
    printf("fd=%d\terrno=:%d,\t%s\n",fd,errno,strerror(errno));
    throw runtime_error("i2c read error");
  else return ret;
}
