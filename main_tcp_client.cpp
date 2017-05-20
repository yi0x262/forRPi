#include"tcp_client.hpp"
#include"kondo_servo.hpp"

#include<vector>
using std::vector;
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;

union sc
{
  unsigned short s;
  char c[2];
}

int main(int argc,const char* argv[]){
  tcp_client tc(argv[1],12345);

  vector<kondo_servo> ks;
  for(int i : {0,1,6,7})ks.push_back(kondo_servo(i));

  while(true){
    string str;
    for(auto k : ks)
    {
      sc r;
      r.s = k.rotate(7500);
      str += r.c;
    }
    cout << str << endl;
    tc.write(str.c_str());
  }

  return 0;

}
