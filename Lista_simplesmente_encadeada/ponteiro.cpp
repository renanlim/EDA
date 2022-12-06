#include <iostream>
using namespace std;

main()
{
    int a, *p;
    a = 30;
    p = &a;
    cout << a << endl;
    cout << *p << endl;
    cout << &a << endl;
    cout << p << endl;
}