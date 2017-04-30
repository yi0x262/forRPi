#include<boost/asio.hpp>
#include<iostream>
#include<string>

using namespace std;
using namespace boost::asio;

int main(){
  ip::tcp::iostream s("www.boost.org","http");

  s << "GET / HTTP/1.0\r\n";
  s << "Host: wwww.boost.org\r\n";
  s << "\r\n";
  s << flush;

  string line;
  while(getline(s,line))cout << line << endl;
  return 0;
}
