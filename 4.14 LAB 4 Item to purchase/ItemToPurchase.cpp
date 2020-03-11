#include "ItemToPurchase.h"
#include <iostream>
using namespace std;


void ItemToPurchase::SetName(string nm){
    name = nm;
}

void ItemToPurchase::SetPrice(int prc){
    price = prc;
}

void ItemToPurchase::SetQuantity(int qty){
    quantity = qty;
}

string ItemToPurchase::GetName() const{
    return name;
}

int ItemToPurchase::GetPrice() const{
    return price;
}

int ItemToPurchase::GetQuantity() const{
    return quantity;
}