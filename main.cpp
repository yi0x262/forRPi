#include"ADCPiPlus.hpp"

#include<iostream>
#include<cstdlib>

int main(int argc,char* argv[])
{
  int address = atoi(argv[1]);
  int channel = atoi(argv[2]);
  int conversion = atoi(argv[3]);
  int bit_rate = atoi(argv[4]);
  int pga = atoi(argv[5]);

  std::cout << address << channel << conversion << bit_rate << pga << std::endl;
  ADCPiPlus adc(address,channel,conversion,bit_rate,pga);
  while(1)std::cout << adc.read() << std::endl;

  return 0;
}
