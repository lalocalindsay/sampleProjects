//
//  virtual.cpp
//  This is an example of a virtual function
//  Virtual functions are used in C++ to support polymorphic behavior
//
//  Created by Lindsay Tucker on 7/24/15.
//  Copyright (c) 2015 Lindsay Tucker. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>


using namespace std;

//global variables
//function prototypes
//class definitions
class A
{

public:
    virtual void mfun ()
    {
        cout << "Base class" << endl;
    }
    
    
};

class B : public A
{

public:
    void mfun()
    {
        cout << "Derived class version" << endl;
    }
    
    
    
};

//methods

int main (void)
{
    
    
    A aObject;
    B bObject;
    
    
    aObject.mfun();
    cout << endl;
    cout << "//Polymorphic behavior (output from derived class):" << endl;
    bObject.mfun();
    
    return 0;
}

