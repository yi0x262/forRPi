#include"RPi_io.hpp"
#include<fcntl.h>//open,close
#include<unistd.h>//write,read

#include<stdexcept>//runtime_error

RPi_io::RPi_io(const char* device)
{
  if((fd = open(device,O_RDWR)) < 0){
    throw std::runtime_error("device open error");
  }
}

int RPi_io::_write(const char* buffer)
{
  return write(fd,buffer,strlen(buffer));
}

int RPi_io::_read(char* buffer)
{
  return read(fd,buffer,sizeof(buffer));
}

RPi_io::~RPi_io()
{
  close(fd);
}
