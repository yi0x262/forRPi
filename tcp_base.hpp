#include<boost/asio.hpp>

class tcp_base
{
protected:
  boost::asio::io_service io_service;
  boost::asio::ip::tcp::socket sock;
public:
  tcp_base(void);
  virtual int write(const char msg[]) = 0;
};
