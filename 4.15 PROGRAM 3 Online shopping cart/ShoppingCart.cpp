#include "ShoppingCart.h"
#include <vector>
#include <iostream>

using namespace std;
    
ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
    
}

ShoppingCart::ShoppingCart(string nm, string date) {
    customerName = nm;
    currentDate = date;
    
}

string ShoppingCart::GetCustomerName() const {
    return customerName;
    
}

string ShoppingCart::GetDate() const {
    return currentDate;
    
}

int ShoppingCart::GetNumItemsInCart() const {
    int num = 0;
    for(unsigned i = 0; i < cartItems.size(); ++i){
        ItemToPurchase item = cartItems.at(i);
        num = num + item.GetQuantity();
    }
   return num; 
}

int ShoppingCart::GetCostOfCart() const {
    int total = 0;
    for(unsigned i = 0; i < cartItems.size(); ++i){
        ItemToPurchase item = cartItems.at(i);
        int prc = item.GetPrice();
        int qty = item.GetQuantity();
        total += (prc*qty);
    }
    return total;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName) {
    bool found = false;
    for(unsigned i = 0; i < cartItems.size(); ++i){
        ItemToPurchase item = cartItems.at(i);
        if(item.GetName() == itemName) {
            found = true;
            cartItems.erase((cartItems.begin() + i));
        } 
    }
    if(!found){
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::ModifyItem(ItemToPurchase item){
    string nm = item.GetName();
    bool found = false;
    for(unsigned i = 0; i < cartItems.size(); ++i){
        ItemToPurchase basic;
        if(cartItems.at(i).GetName() == nm) {
            found = true;
            if(item.GetDescription() != basic.GetDescription()){
            cartItems.at(i).SetDescription(item.GetDescription());  
            }
            if(item.GetPrice() != basic.GetPrice()){
            cartItems.at(i).SetPrice(item.GetPrice());   
            }
            if(!(item.GetQuantity() == basic.GetQuantity())){
            cartItems.at(i).SetQuantity(item.GetQuantity());   
            }
        } 
    }
    if(!found){
        cout << "Item not found in cart. Nothing modified." << endl;
        cout << endl;
    }
}

void ShoppingCart::PrintTotal()const {
    if(cartItems.size() == 0){
        cout << customerName << "'s Shopping Cart - " << currentDate << endl;
        cout << "Number of Items: " << GetNumItemsInCart() << endl;
        cout << endl;
        cout << "SHOPPING CART IS EMPTY" << endl;
        cout << endl;
        cout << "Total: $" << GetCostOfCart() << endl;
    }
    else {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl;
    cout << endl;
    for(unsigned i = 0; i < cartItems.size(); ++i){
        ItemToPurchase item = cartItems.at(i);
        int total = item.GetQuantity()*item.GetPrice();
        cout << item.GetName() << " " << item.GetQuantity() << " @ $" << item.GetPrice() << " = $" << total << endl;
    }
    cout << endl;
    cout << "Total: $" << GetCostOfCart() << endl;
    }
}


void ShoppingCart::PrintDescription() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for(unsigned i = 0; i+1 < cartItems.size(); ++i){
        ItemToPurchase item = cartItems.at(i);
        cout << item.GetName() << ": " << item.GetDescription() << endl;
    }
    ItemToPurchase last = cartItems.at(cartItems.size()-1);
    cout << last.GetName() << ": " << last.GetDescription();
    cout << endl;
}