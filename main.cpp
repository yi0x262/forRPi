#include"ADCPiPlus.hpp"

#include<iostream>
#include<cstdlib>

int main(int argc,char* argv[])
{
  int address = atoi(argv[1]);
  int channel = atoi(argv[2]);
  int conversion = atoi(argv[3]);
  int bit_rate = atoi(argv[4]);

  std::cout << address << channel << conversion << bit_rate << std::endl;
  ADCPiPlus adc(address,channel,conversion,bit_rate,1);
  while(1)std::cout << adc.read() << std::endl;

  return 0;
}
