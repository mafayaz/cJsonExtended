#ifndef CJSONEXTENDED_EXCEPTION_H
#define CJSONEXTENDED_EXCEPTION_H

class json_exception : public std::exception
  {
  public:
    json_exception(const std::string m="json exception"):msg(m){}
    ~json_exception(void) throw() {}
    virtual const char* what(){return msg.c_str();}
  private:
    std::string msg;
  };

#endif // CJSONEXTENDED_EXCEPTION_H
  