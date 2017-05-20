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
};

int main(int argc,const char* argv[]){
  //tcp_client tc(argv[1],12345);

  //vector<kondo_servo> ks;
  kondo_servo* ks[4];
  int n = 0;
  for(int i : {0,1,6,7})ks[n++] = new kondo_servo(i);

  while(true){
    string str;
    for(auto k : ks)
    {
      sc r;
      r.s = k.rotate(11500);
      str += r.c;
      cout << r.s << endl;
    }
    //tc.write(str.c_str());
  }

  return 0;

}
