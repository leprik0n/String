#pragma once
#include <ostream>

class String
{
private:
    char *str;

public:

    String();

    String(const char*);

    String(char, unsigned int);

    String(const String &);

    String(String &&);

    ~String();

    String &operator=(const String &);

    String &operator=(String &&);

    String &operator+=(const String &);

    String &operator+=(const char*);

    String &operator+=(char);

    char &operator[](unsigned int);

    const char &operator[](unsigned int)const;

    unsigned int Size();

    void Swap(String &);

    const char* c_str()const;

    friend std::ostream &operator<<(std::ostream &,const String &);

    friend std::istream &operator>>(std::istream &,String &);

    friend String operator+(const String &,const String &);

    friend String operator+(const String &,const char*);

    friend String operator+(const char*,const String &);

    friend String operator+(const String &,const char);

    friend String operator+(const char,const String &);

    friend bool operator==(const String &,const String &);

    friend bool operator!=(const String &,const String &);

    friend bool operator <=(const String &,const String &);

    friend bool operator>(const String &,const String &);

    friend bool operator<(const String &,const String &);

    friend bool operator >=(const String &,const String &);

};
