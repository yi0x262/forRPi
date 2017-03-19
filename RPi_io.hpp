class RPi_io
{
  int fd;//file discriptor
protected:
  virtual int _read(char buf[]) = 0;
  virtual int _write(char buf[]) = 0;
public:
  RPi_io(const char* device);
  ~RPi_io();
}
