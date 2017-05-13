#include"kondo_servo.hpp"

#include<cstdlib>
#include<vector>
using std::vector;

#include<iostream>

int main(int argc, char* argv[])
{
  vector<kondo_servo> ks;
  for(int i = 1; i < argc; ++i)ks.push_back(kondo_servo(atoi(argv[i])));

  for(auto k:ks)
  {
    std::cout << static_cast<int>(k.current()) << " " << static_cast<int>(k.temperature()) << std::endl;
  }

  return 0;
}
