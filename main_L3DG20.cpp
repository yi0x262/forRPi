#include"L3DG20.hpp"

#include<iostream>
#include<stdio.h>
#include<unistd.h>//usleep

int main(int argc,char* argv[])
{
  L3DG20 l;
  while(1)
  {
    std::cout << l.read_x() << "x\n";
    usleep(atoi(argv[1]));
    std::cout << l.read_y() << "y\n";
    usleep(atoi(argv[1]));
    std::cout << l.read_z() << "z\n";
    usleep(atoi(argv[1]));
  }
  return 0;
}
