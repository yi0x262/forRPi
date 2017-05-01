#include"tcp_base.hpp"

tcp_base::tcp_base(void):sock(boost::asio::ip::tcp::socket(io_service)){}
