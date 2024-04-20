#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;
class Base{
public:
    virtual ostream&print(ostream & os){
        return os << "this is base class";
    }
    friend ostream&operator<<(ostream & os,Base &base){
        return base.print(os);
    }
};
class Son:public Base{
public:
    virtual ostream&print(ostream & os) override{
        return os << "this is son class";
    }
    // friend ostream&operator<<(ostream & os,Son & son){
    //     return son.print(os);
    // }
};
int main() {
    Base * p = new Son();
    p->print(cout << "see class:\n")<<"\nnb\n";
    cout << (*p);
    Son * s = new Son();
    cout << (*s);
    return 0;
}
