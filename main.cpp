#include"ADCPiPlus.hpp"

#include<iostream>
#include<cstdlib>
#include<vector>

int main(int argc,char* argv[])
{
  std::vector<ADCPiPlus> adc;

  int address = atoi(argv[1]);
  int conversion = atoi(argv[2]);
  int bit_rate = atoi(argv[3]);

  std::cout << address << conversion << bit_rate << std::endl;
  for(auto c:{1,2,3,4})adc.push_back(ADCPiPlus(address,c,conversion,bit_rate,1));
  while(1)
  {
    for(auto& a : adc)std::cout << a.read();
    std::cout << std::endl;
  }

  return 0;
}
