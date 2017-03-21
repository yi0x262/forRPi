class RPi_io
{
protected:
  int fd;//file discriptor
  virtual int _read(char buf[]) = 0;
  virtual int _write(char buf[]) = 0;
public:
  RPi_io(const char* device);
  virtual ~RPi_io();
};
