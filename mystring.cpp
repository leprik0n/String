#include <iostream>
#include <stdexcept>
#include "mystring.h"
#include <cstring>
//#include "lib.h"
using namespace std;

template<typename t>
void swop(t& a, t& b)
{
    t tmp=a;
    a=b;
    b=tmp;
}

void String::Swap(String& p)
{
    swop(str,p.str);
}

String::String()
    :str(""){}

String::String(char ch,unsigned int s)
    :str(new char[s+1])
{
    for(unsigned int i = 0; i < s; i++){
            str[i] = ch;
    }
}

String::String(const char* s)
    :str{new char[strlen(s)+1]}
{
    strcpy(str,s);
}

String::String(const String& p)
    :str(new char[strlen(p.str)+1])
{
    strcpy(str,p.str);
}

String::String(String&& other)
    :str{other.str}
{
    other = nullptr;
}

String::~String()
{
    delete[]str;
}

String& String::operator=(const String& p)
{
    String tmp(p);
    Swap(tmp);
    return *this;
}

String& String::operator=(String&& other)
{
    delete[]str;
    str = other.str;
    other.str = nullptr;
    return *this;
}

String& String::operator+=(const String& p)
{
    if(p.str){
        strcat(str,p.str);
    }
    return *this;
}

String& String::operator+=(const char* ss)
{
    if(ss){
        strcat(str,ss);
    }
    return *this;
}

String&String::operator+=(char suffix)
{
    if(suffix){
        //s_c(str,suffix);
    }
    return *this;
}

char& String::operator[](unsigned int i)
{
    if(i >= strlen(str)){
            throw out_of_range("out_of_range");
    }
    return str[i];
}

const char& String::operator[](unsigned int i)const
{
    if(i >= strlen(str)){
            throw out_of_range("out_of_range");
    }
    return str[i];
}

unsigned int String::Size()
{
    return strlen(str);
}

bool operator==(const String& s,const String& p)
{
    return strcmp(s.str,p.str);
}

bool operator<(const String& p,const String& s)
{
    return (strlen(p.str) < strlen(s.str))?true:false;
}

String operator+(const String& p,const String& s)
{
    return String(p) += s;
}

String operator+(const String& p,const char* s)
{
    return String(p) += s;
}

String operator+(const char* s,const String& p)
{
    return String(p) += s;
}

String operator+(const String& p,const char suffix)
{
    return String(p) += suffix;
}

String operator+(const char suffix,const String& p)
{
    return String(p) += suffix;
}

bool operator!=(const String& p,const String& s)
{
    return !(p.str == s.str);
}

bool operator <=(const String& p,const String& s)
{
    return (strlen(p.str) <= strlen(s.str))?true:false;
}

bool operator>(const String& p,const String & s)
{
    return(strlen(p.str) > strlen(s.str))?true:false;
}

bool operator >=(const String&p,const String&s)
{
    return (strlen(p.str) >= strlen(s.str))?true:false;
}

ostream& operator<<(ostream& os,const String& p)
{
    os<<p.str<<' ';
    return os;
}

istream& operator>>(istream& io,String& p)
{
    char lhs[128];
    io.getline(lhs,sizeof(lhs));
    p = lhs;
    return io;
}

const char* String::c_str()const
{
    return str;
}
