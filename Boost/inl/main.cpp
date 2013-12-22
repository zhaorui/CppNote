#include "Value.h"
#include <iostream>
using namespace std;

int main(int argc, char**argv)
{
    Value var("hello world");
    cout<<var.getVal()<<endl;
}
