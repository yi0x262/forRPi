//If it could, i2c_descriptor should inherit 'file'... but I gave up.
#include"i2c_descriptor.hpp"

#include<fcntl.h>//open,write,read
#include<unistd.h>//close
#include<sys/ioctl.h>//ioctl
#include<linux/i2c-dev.h>//I2C_SLAVE
#include<cstring>//strlen

#include<cerrno>//errno
#include<system_error>//system_error,

int i2c_descriptor::instance_counter = 0;
file* i2c_descriptor::fd = nullptr;

i2c_descriptor::i2c_descriptor(const char device[], const int address)
{
  ++instance_counter;

  if(fd != nullptr)return;//guard

  fd(device);

  if(ioctl(fd.descriptor,I2C_SLAVE,address) < 0){
    throw std::system_error(errno,std::system_category());
  }
}

#ifdef _debug
#include<iostream>
#endif

i2c_descriptor::~i2c_descriptor()
{
  #ifdef _debug
  std::cout << "i2c #" << instance_counter << " closed" << std::endl;
  #endif
}

char read_byte(const char buf) const
{
  char ret;
  if(fd._write(&buf)&&fd._read(&ret,1)){
    return ret;
  }
  throw std::system_error(errno,std::system_category());
}
