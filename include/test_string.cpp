#include <iostream>
#include <stdexcept>
#include <new>
#include "string.h"
#include <assert.h>
#include <cstring>
using namespace std;

String c_move(const char*s)
{
    return String(s);
}
String c_move_s(const String& p)
{
    return p;
}

void ctor_novalue()
{
    String s;
    assert(s.Size() == 0);
    assert(strcmp(s.c_str(),"") == 0);
    cout<<"1_OK"<<endl;
}

void ctor_char()
{
    String s('a',3);
    assert(s.Size() == 3);
    assert(strcmp(s.c_str(),"aaa") == 0);
    cout<<"2_OK"<<endl;
}

void ctor_string()
{
    String s{"hello world"};
    assert(strlen(s.c_str()) == 11);
    assert(strcmp(s.c_str(),"hello world") == 0);
    cout<<"3_OK"<<endl;
}

void ctor_copy()
{
    String s{"string"};
    String s_copy{s};
    assert(strlen(s_copy.c_str()) == strlen(s.c_str()));
    assert(strcmp(s_copy.c_str(),s.c_str()) == 0);
    cout<<"4_OK"<<endl;
}

void ctor_move()
{
    String s = c_move("hello");
    assert(strlen(s.c_str()) == 5);
    assert(strcmp(s.c_str(),"hello") == 0);
    cout<<"5_OK"<<endl;
}

void oper_copy_equal()
{
    String s{"hello"};
    String k = s;
    assert(strlen(k.c_str()) == strlen(s.c_str()));
    assert(strcmp(k.c_str(),s.c_str()) == 0);
    cout<<"6_OK"<<endl;
}

void oper_move_equal()
{
    String s{"hello"};
    String k = c_move_s(s);
    assert(strlen(k.c_str()) == 5);
    assert(strcmp(k.c_str(),"hello") == 0);
    cout<<"7_OK"<<endl;
}

void oper_plus_equal_class()
{
    String s{"low"};
    String l{" skill"};
    s += l;
    assert(strlen(s.c_str()) == 9);
    assert(strcmp(s.c_str(),"low skill") == 0);
    cout<<"8_OK"<<endl;
}

void oper_plus_equal_string()
{
    String s{"job"};
    s += " very hard";
    assert(strlen(s.c_str()) == 13);
    assert(strcmp(s.c_str(),"job very hard") == 0);
    cout<<"9_OK"<<endl;
}

void oper_plus_equal_char()
{
    String s{"number="};
    s += '5';
    assert(strlen(s.c_str()) == 8);
    assert(strcmp(s.c_str(),"number=5") == 0);
    cout<<"10_OK"<<endl;
}

void oper_plus_class()
{
    String s{"hello"};
    String g{"world"};
    String v = s + g;
    assert(strlen(v.c_str()) == 10);
    assert(strcmp(v.c_str(),"helloworld") == 0);
    cout<<"11_OK"<<endl;
}

void oper_plus_string_right()
{
    String k{"main"};
    String s = k + "prog";
    assert(strlen(s.c_str()) == 8);
    assert(strcmp(s.c_str(),"mainprog") == 0);
    cout<<"12_OK"<<endl;
}

void oper_plus_string_left()
{
    String k{"main"};
    String s = "prog" + k;
    assert(strlen(s.c_str()) == 8);
    assert(strcmp(s.c_str(),"mainprog") == 0);
    cout<<"13_OK"<<endl;
}

void oper_plus_char_right()
{
    String k{"abc"};
    String s = k + 'd';
    assert(strlen(s.c_str()) == 4);
    assert(strcmp(s.c_str(),"abcd") == 0);
    cout<<"14_OK"<<endl;
}

void oper_plus_char_left()
{
    String k{"abc"};
    String s = 'd' + k;
    assert(strlen(s.c_str()) == 4);
    assert(strcmp(s.c_str(),"abcd") == 0);
    cout<<"15_OK"<<endl;

}

void oper_equal()
{
    String lhs{"hello"};
    String rhs{"hell0"};
    bool b = (lhs == rhs);
    assert(b == false);
    cout<<"16_OK"<<endl;
}

void oper_not_equal()
{
    String lhs{"hello"};
    String rhs{"hell0"};
    bool b = (lhs != rhs);
    assert(b == true);
    cout<<"17_OK"<<endl;
}

void oper_less_equal()
{
    String lhs{"hello"};
    String rhs{"hellofs"};
    bool b = (lhs <= rhs);
    assert(b == true);
    cout<<"18_OK"<<endl;
}

void oper_more()
{
    String lhs{"hello"};
    String rhs{"help"};
    bool b = (lhs > rhs);
    assert(b == true);
    cout<<"19_OK"<<endl;
}

void oper_less()
{
    String lhs{"hello"};
    String rhs{"helps"};
    bool b = (lhs > rhs);
    assert(b == false);
    cout<<"20_OK"<<endl;
}

void oper_more_equal()
{
    String lhs{"hello"};
    String rhs{"helps"};
    bool b = (lhs >= rhs);
    assert(b == true);
    cout<<"21_OK"<<endl;
}

int main()
{

try
{


ctor_novalue();
ctor_char();
ctor_string();
ctor_copy();
ctor_move();
oper_copy_equal();
oper_move_equal();
oper_plus_equal_class();
oper_plus_equal_string();
oper_plus_equal_char();
oper_plus_class();
oper_plus_string_right();
oper_plus_string_left();
oper_plus_char_right();
oper_plus_char_left();
oper_equal();
oper_not_equal();
oper_less();
oper_more();
oper_less_equal();
oper_more_equal();



}

catch(const bad_alloc&oop)
{
    cout<<"exception:"<<oop.what()<<endl;
}

catch(const std::out_of_range& oop)
{
    cout<<"exception:"<<oop.what()<<endl;
}

    return 0;
}

