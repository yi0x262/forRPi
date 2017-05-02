#include"file_descriptor.hpp"

class kondo_servo
{
  const int id;
  file fd;
public:
  kondo_servo(const int servo_id);

  unsigned short rotate(unsigned short target_angle);//2byte
  char current(void);//1byte
  char temperature(void);//1byte

  ~kondo_servo();
};
