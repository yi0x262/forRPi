class RPi_io
{
  int fd;//file discriptor
protected:
  int _read(char* buf);
  int _write(const char* buf);  
public:
  RPi_io(const char* device);
  ~RPi_io();
}
