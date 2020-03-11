#include "IntVector.h"
#include <stdexcept>
using namespace std;

    IntVector::IntVector() {
        sz = 0;
        cap = 0;
        data = nullptr;
    }

    IntVector::IntVector(unsigned size, int value) {
       sz = size;
        cap = size;
        data = new int[cap];
        
        for(unsigned i = 0; i < size; ++i) {
           data[i] = value; 
        }
    }

    IntVector::~IntVector() {
        delete[] data;
        data = nullptr;
    }

    unsigned IntVector::size() const {
        return sz;
    }

    unsigned IntVector::capacity() const {
        return cap;
    }

    bool IntVector::empty() const {
        return (sz == 0);
    }

    const int& IntVector::at(unsigned index) const {
        if(empty() || index >= sz || sz  == 0){
            throw out_of_range("IntVector::at_range_check");
        } else {
        return data[index];
        }
    }

    int& IntVector::at(unsigned index) {
        if(empty() || index >= sz || sz  == 0){
        throw out_of_range("IntVector::at_range_check");
        } else {
        return data[index];
        }
    }

    void IntVector::insert(unsigned index, int value) {
        if(index > sz){
            throw out_of_range("IntVector::insert_range_check"); 
        }
        else {
            if(sz >= cap){
            expand();
            }
            for(unsigned i = sz; i > index; --i){
                data[i] = data[i-1];
            }
            data[index] = value;
            ++sz; 
        }
    }

    void IntVector::erase(unsigned index){
         if(index >= sz){
          throw out_of_range("IntVector::erase_range_check");  
        }
        for(unsigned i = index; i+1 < sz; ++i){
            data[i] = data[i+1];
        }
        --sz;
    }

    const int& IntVector::front() const {
        if(sz > 0){
        return data[0];  
        } else {
        throw out_of_range("IntVector::at_range_check");    
        } 
    }

    int& IntVector::front() {
        if(sz > 0){
        return data[0];  
        } else {
        throw out_of_range("IntVector::at_range_check");    
        } 
    }

    const int& IntVector::back() const {
        if(sz > 0){
        return data[sz-1];    
        } else {
        throw out_of_range("IntVector::at_range_check"); 
        }  
    }

    int& IntVector::back(){
        if(sz > 0){
        return data[sz-1];    
        } else {
        throw out_of_range("IntVector::at_range_check"); 
        } 
    }

  void IntVector::assign(unsigned n, int value) {
       if(n > cap*2){
           expand(n-cap);
       } else if(n > cap) {
           expand();
       }
        for(unsigned i = 0; i < n; ++i) {
            data[i] = value;
        }
      sz = n;
    }  

    void IntVector::push_back(int value) {
        if(sz >= cap){
            expand();
        }
        data[sz] = value;
        ++sz;
    }

    void IntVector::pop_back() {
        if(sz!= 0){
        --sz;
        }
    }

    void IntVector::clear() {
        sz = 0;
    }

   void IntVector::resize(unsigned n, int value) { 
       if(cap < n){
           if(n > cap*2){
                expand(n-cap);
                for(unsigned i = sz;i < n; ++i){
                    data[i] = value;
                }
                sz = n;
            } 
           else if(n > cap) {
               expand();
                for(unsigned i = sz;i < n; ++i) {
                    data[i] = value;
                }
                sz = n;
           }
       } else{
            if(n > sz){
                for(unsigned i = sz;i < n; ++i) {
                data[i] = value;
                }
                sz = n;
            }
            if(n < sz){
                sz = n;
            }
       }
    }

    void IntVector::reserve(unsigned n) {
        if(n > cap) {
           cap = n;
        }
    }

    void IntVector::expand() {
        if(cap == 0){
        data = new int[1];
        data[0] = 0;
        cap = 1;
        }
        else {
            unsigned tempCap = cap*2;
            int* tempData = new int[tempCap];   
            for(unsigned i = 0; i < sz; ++i){
                tempData[i] = data[i];    
            }
            delete[] data;
            data = tempData;
            cap = tempCap;
        }
    }

    void IntVector::expand(unsigned amount) {
        unsigned tempCap = cap + amount;
        int* tempData = new int[tempCap];
        if (data != nullptr){
            for(unsigned i = 0; i < sz; ++i){
            tempData[i] = data[i];
            }
        }
        delete[] data;
        data = tempData;
        cap = tempCap;
    }