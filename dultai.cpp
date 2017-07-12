#include<iostream>  
using namespace std;  
  
class A  
{  
public:  
    void foo()  
    {  
        printf("1\n");  
    }  
    virtual void fun()  
    {  
        printf("2\n");  
    }  
};  
class B : public A  
{  
public:  
    void foo()  
    {  
        printf("3\n");  
    }  
    void fun()  
    {  
        printf("4\n");  
    }  
};  
int main(void)  
{  
    A a;  
    B b;  
    B *p1;

    A *p = &a;  
    p->foo();  
    p->fun();  
    p = &b;  
    p->foo();  
    p->fun();  

    p1 = &b;
    p1->foo();
    p1->fun();

//    B *ptr = (B *)&a;  ptr->foo();  ptr->fun();

    return 0;  
}  