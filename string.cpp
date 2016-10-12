#include <iostream>
#include <stdexcept>
#include "String.h"
using namespace std;

int len(const char* s)
{
    unsigned int k=0;
    while(*s++)k++;
    return k;
}

int cmp(const char* lhs,const char* rhs)
{
    int i = 0;
    for (;lhs[i] == rhs[i] && i < len(lhs); i++);
    return (i == len(lhs)) ? true : false;
}

void s_copy(char* lhs,const char* rhs)
{
    while(*lhs++ = *rhs++);
}

void s_cat(char*& lhs,const char* rhs)
{
    unsigned int raz = len(lhs)+len(rhs)+1;
    char* ptr = new char[len(lhs)+1];
    s_copy(ptr,lhs);
    delete[]lhs;
    lhs=new char[raz];
    s_copy(lhs,ptr);
    for(unsigned int i = len(ptr),j = 0 ; i <= raz; i++, j++){
        lhs[i] = rhs[j];
    }
    delete[]ptr;
}

void s_c(char*& lhs, const char rhs)
{
    char*ptr = new char[len(lhs)+2];
    s_copy(ptr,lhs);
    delete[]lhs;
    int i = len(ptr);
    ptr[i] = rhs;
    ptr[i+1] = '\0';
    lhs = new char[len(ptr)+1];
    s_copy(lhs,ptr);
    delete[]ptr;
}

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
    :str{new char[len(s)+1]}
{
    s_copy(str,s);
}

String::String(const String& p)
    :str(new char[len(p.str)+1])
{
    s_copy(str,p.str);
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
        s_cat(str,p.str);
    }
    return *this;
}

String& String::operator+=(const char* ss)
{
    if(ss){
        s_cat(str,ss);
    }
    return *this;
}

String&String::operator+=(char suffix)
{
    if(suffix){
        s_c(str,suffix);
    }
    return *this;
}

char& String::operator[](unsigned int i)
{
    if(i >= len(str)){
            throw out_of_range("out_of_range");
    }
    return str[i];
}

const char& String::operator[](unsigned int i)const
{
    if(i >= len(str)){
            throw out_of_range("out_of_range");
    }
    return str[i];
}

unsigned int String::Size()
{
    return len(str);
}

bool operator==(const String& s,const String& p)
{
    return cmp(s.str,p.str);
}

bool operator<(const String& p,const String& s)
{
    return (len(p.str) < len(s.str))?true:false;
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
    return (len(p.str) <= len(s.str))?true:false;
}

bool operator>(const String& p,const String & s)
{
    return(len(p.str) > len(s.str))?true:false;
}

bool operator >=(const String&p,const String&s)
{
    return (len(p.str) >= len(s.str))?true:false;
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
