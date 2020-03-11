#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

ItemToPurchase::ItemToPurchase(){
    name = "none";
    itemDescription = "none";
    price = 0;
    quantity = 0;
}

ItemToPurchase::ItemToPurchase(string nm, string description, int prc, int qty){
    name = nm;
    itemDescription = description;
    price = prc;
    quantity = qty;
}

void ItemToPurchase::SetName(string nm){
    name = nm;
}

void ItemToPurchase::SetPrice(int prc){
    price = prc;
}

void ItemToPurchase::SetQuantity(int qty){
    quantity = qty;
}

void ItemToPurchase::SetDescription(string description){
    itemDescription = description;
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

string ItemToPurchase::GetDescription() const{
    return itemDescription;
}

void ItemToPurchase::PrintItemCost() const{
    int total = quantity*price;
    cout << name << " " << quantity << " @ $" << price << " = $" << total;
}

void ItemToPurchase::PrintItemDescription() const{
    cout << name << ": " << itemDescription << ".";
}