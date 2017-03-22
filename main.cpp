#include"ADCPiPlus.hpp"

#include<iostream>

int main()
{
  ADCPiPlus adc = ADCPiPlus(0x68,1,0,18,1);
  adc.read();

  return 0;
}
