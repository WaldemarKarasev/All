#include <iostream>
#include <vector>
#include <string>

class A
{
private:
    /* data */
public:
    A()
    {
        std::cout << "A() constructor" << std::endl;
    }
    ~A()
    {
        std::cout << "A() destructor" << std::endl;
    }
};

class B
{
private:
    /* data */
public:
    B()
    {
        std::cout << "B() constructor" << std::endl;
    }
    ~B()
    {
        std::cout << "B() destructor" << std::endl;
    }
};

class C
{
private:
    /* data */
public:
    C()
    {
        std::cout << "C() constructor" << std::endl;
    }
    ~C()
    {
        std::cout << "C() constructor" << std::endl;
  
    }
};


class D
{

public:
    typedef struct Two
    {
        int a;
        int b;
    } Two;
    
    static C c;
    D()
    {
        std::cout << "D() constructor" << std::endl;
    }
    ~D()
    {
        std::cout << "D() destructor" << std::endl;
        One d;
        Two  t;
    }
    
private:
    typedef struct One
    {
        int a;
        int b;
    } One;
    
    A a;
    B b;
    One o;
    Two t;
public:
typedef std::vector<std::string> strVec;
One oo;
    Two tt;
};

C D::c;