#include"file_descriptor.hpp"

class kondo_servo
{
  const int id;
  file fd;
  char get_state(int sc)const;
public:
  kondo_servo(const int servo_id);

  unsigned short rotate(unsigned short target_angle);//2byte
  char current(void)const;//1byte
  char temperature(void)const;//1byte

  ~kondo_servo();
};
