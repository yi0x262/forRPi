#include"kondo_servo.hpp"

#include<cstdlib>
#include<vector>
using std::vector;

int main(int argc, char* argv[])
{
  vector<kondo_servo> ks;
  for(int i = 1; i < argc; ++i)ks.push_back(kondo_servo(atoi(argv[i])));

  return 0;
}
