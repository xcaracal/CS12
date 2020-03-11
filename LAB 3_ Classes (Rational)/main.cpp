#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here

//Other Constructors
Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int numerator){
    this->numerator = numerator;
    denominator = 1;
}

Rational::Rational(int numerator, int denominator){
    this->numerator = numerator;
        if(denominator != 0){
        this->denominator = denominator;
        }
}

//Private Member Funstions
const Rational Rational::add(const Rational &obj) const{
Rational temp = obj;
int num;
int den;
num = ((numerator*temp.denominator)+(denominator*temp.numerator));
den = (denominator*temp.denominator);
Rational done(num, den);
return done;
} 

const Rational Rational::subtract(const Rational &obj) const{
Rational temp = obj;
int num;
int den;
num = ((numerator*temp.denominator)-(denominator*temp.numerator));
den = (denominator*temp.denominator);
Rational done(num, den);
return done;

}

const Rational Rational::multiply(const Rational &obj) const{
Rational temp = obj;
int num;
int den;
 num = (numerator*temp.numerator);
 den = (denominator*temp.denominator);
 Rational done(num, den);
return done;
}

const Rational Rational::divide(const Rational &obj) const{
Rational temp = obj;
int num;
int den;
num= (numerator*temp.denominator);
den= (denominator*temp.numerator);
Rational done(num, den);
return done;
}

int Rational::gcd(int num, int den) const{
    int big;
    int small;
    if (denominator > numerator){
        big = denominator;
        small = numerator;
    }
    else{
        big = numerator;
        small = denominator;
    }
    while(big%small != 0){
        int temp = big%small;
        big = small;
        small = temp;
    }
    return small;
}

void Rational::simplify(){
   int x = gcd(numerator, denominator);
    numerator = numerator/x;
    denominator = denominator/x;
    
}
//Get function
void Rational::display() const{
    cout << numerator << " / " << denominator;
}


// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

