#include "IntVector.h"
#include <iostream>

using namespace std;

int main(){
    IntVector a = IntVector();
    IntVector b = IntVector(10, 4);
    cout << "a Size: " << a.size() << endl;
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
    return 0;
}