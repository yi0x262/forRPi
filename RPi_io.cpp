#include"RPi_io.hpp"
#include<stdio.h>//perror
#include<fcntl.h>//open,close
#include<unistd.h>//close
#include<stdexcept>//runtime_error
#include<errno.h>
RPi_io::RPi_io(const char* device)
{
  if((fd = open(device,O_RDWR)) < 0){
    printf("fd=%d\terrno=:%d,\t%s\n",fd,errno,strerror(errno));
    throw std::runtime_error("device open error");
  }
}

RPi_io::~RPi_io()
{
  close(fd);
}
