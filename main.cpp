#include"ADCPiPlus.hpp"

#include<iostream>

int main()
{
  ADCPiPlus adc = ADCPiPlus(0x68,1,0,18,1);
  while(1)std::cout << adc.read() << std::endl;

  return 0;
}
