#include"file_descriptor.hpp"

#include<fcntl.h>//open,read,write
#include<unistd.h>//close
#include<string.h>//strlen
#include<cerrno>
#include<system_error>

#include<iostream>
#define print(var) std::cout << #var << ":" << var << std::endl;

file::file(const char* device) : descriptor(open(device,O_RDWR))
{
  if(descriptor < 0){
    throw std::system_error(errno,std::system_category());
  }

  #ifdef _debug
  print(descriptor);
  #endif
}

int file::get_descriptor(void)const{return descriptor;}

int file::_read(char buf[],int size) const
{
  #ifdef _debug
  print(sizeof(buf))
  #endif

  return read(descriptor,buf,size);
}

int file::_write(const char buf[]) const
{
  #ifdef _debug
  std::cout << strlen(buf) << strlen(buf) << std::endl;
  #endif

  return write(descriptor,buf,strlen(buf));
}

file::~file()
{
  close(descriptor);
}
