class file
{
protected:
  const int descriptor;
public:
  file(const char* device);
  ~file();
  int _write(const char buf[])const;
  int _read(char buf[],unsigned size)const;
};
