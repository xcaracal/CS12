#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string, char);

int main() {
   string filename;
   char ch;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;
   
   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(string nm, char ch){
    ifstream fin;
    char x;
    int cnt;
    
    fin.open(nm.c_str());
    if(!fin.is_open()){
        cout << "Error opening " << nm << endl;
        exit(1);
    }
    while(!fin.eof()){
        fin.get(x);
        if(x == ch){
        cnt++;
        }
    }
    fin.close();
    return cnt;
    
}