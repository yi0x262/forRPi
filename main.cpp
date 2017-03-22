#include"ADCPiPlus.hpp"

#include<iostream>
#include<cstdlib>

int main(int argc,char* argv[])
{
  ADCPiPlus adc[4];

  int address = atoi(argv[1]);
  //int channel = atoi(argv[2]);
  int conversion = atoi(argv[2]);
  int bit_rate = atoi(argv[3]);

  std::cout << address << conversion << bit_rate << std::endl;
  for(int c = 0; c < 4; ++c)adc[c] = ADCPiPlus(address,c+1,conversion,bit_rate,1);
  while(1)
  {
    for(auto& a : adc)std::cout << a.read()
    std::cout << std::endl;
  }

  return 0;
}
