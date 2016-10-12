#ifndef LIB_H_
#define LIB_H_

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

#endif // LIB_H_
