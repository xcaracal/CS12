#include "IntVector.h"
#include <iostream>

using namespace std;

int main(){
    IntVector a = IntVector();
    IntVector b = IntVector(10, 4);
    /*cout << "a Size: " << a.size() << endl;
    cout << "b Size: " << b.size() << endl; 
    cout << "a Empty?" << a.empty() << endl;
    cout << "b Empty?" << b.empty() << endl;
    cout << "Front: a b -" << a.front() << " " << b.front() <<endl;
    cout << "Back: a b -" << a.back() << " " << b.back() <<endl;
    cout << "Index:" << endl;
    cout << "a - " << a.at(0) << endl;
    cout << "b - " << b.at(5) << endl;
    cout << "b Excception- " << b.at(10) << endl;
    cout << "b Excception- " << b.at(0) << endl;
    */
    for(unsigned i = 0; i < b.size(); ++i) {
        cout << b.at(i);
    }
    cout << endl;
    b.pop_back();
    for(unsigned i = 0; i < b.size(); ++i) {
        cout << b.at(i);
    }
    cout << endl;
    //b.clear();
    /* for(unsigned i = 0; i < b.size(); ++i) {
        cout << a.at(i) << endl;
    }
    a.insert(0, 12);
    cout << a.at(0) << endl;
    a.insert(a.size(), 15);
    cout << a.at(a.size()-1) << endl;
    b.resize(100, 0);
    b.resize(2,0);
    cout << b.size() << endl;
    b.resize(0,0);
    cout << b.size() << endl;
    */
    /*b.resize(19,0);
    cout << b.size() << endl;
    b.resize(10,0);
    cout << b.size() << endl;
    b.resize(0,0);
    cout << b.size() << endl;
    b.reserve(19);
    cout << b.size() << endl;
    b.reserve(10);
    cout << b.size() << endl;
    b.reserve(0);
    cout << b.size() << endl;
    */
    cout << a.capacity() << endl;
    cout << b.capacity() << endl;
    b.front();
    b.front() = 2;
    b.front();
    cout <<  b.back() << endl;
    b.back() = 2;
    cout << b.back() << endl;
    
    return 0;
}