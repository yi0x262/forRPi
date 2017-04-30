#include<boost/asio.hpp>

class tcp_base
{
  const boost::asio::io_service io_service;
  const boost::asio::ip::tcp::socket sock;
public:
  tcp_base(void);
  virtual int transceive()
}
