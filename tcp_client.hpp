#include"tcp_base.hpp"
#include<string>

class tcp_client:public tcp_base
{
public:
  tcp_client(const char server_name[],const u_short port_num);
  int write(char msg[])const;
  std::string receive(void);
  std::string transceive(char msg[]);
  ~tcp_client();
};
