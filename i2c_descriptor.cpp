//If it could, i2c_descriptor should inherit 'file'... but I gave up.
#include"i2c_descriptor.hpp"

#include<fcntl.h>//open,write,read
#include<unistd.h>//close
#include<sys/ioctl.h>//ioctl
#include<linux/i2c-dev.h>//I2C_SLAVE

#include<cerrno>//errno
#include<system_error>//system_error,

int i2c_descriptor::descriptor = -1;
int i2c_descriptor::instance_counter = 0;

i2c_descriptor::i2c_descriptor(const char device[], const int address)
{
  ++instance_counter;

  if(descriptor >= 0)return;

  if((descriptor = open(device,O_RDWR)) >= 0)
  {
    if(ioctl(descriptor,I2C_SLAVE,address) >= 0)
    {
      return;
    }
  }
  //descrriptor < 0 and (open < 0 or ioctl < 0)
  throw std::system_error(errno,std::system_category());
}


i2c_descriptor::~i2c_descriptor()
{
  if(--instance_counter == 0)
  {
    close(descriptor);
  }
}


int get_descriptor(void)const
{
  return desciptor;
}


int i2c_descriptor::_write(char buf[])const
{
  return write(descriptor,buf,strlen(buf));
}


int i2c_descriptor::_read(char buf[],int bufsize)const
{
  return read(descriptor,buf,bufsize);
}
