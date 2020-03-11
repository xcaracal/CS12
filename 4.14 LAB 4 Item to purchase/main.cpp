#include "ItemToPurchase.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<ItemToPurchase> itemList;
    unsigned i;
    for(i = 1; i <= 2; ++i){
    ItemToPurchase item;
    string nm;
    int prc;
    int qty;
    cout << "Item " << i << endl;
    cout << "Enter the item name:";
    getline(cin, nm);
    item.SetName(nm);
    cout <<endl;
    cout << "Enter the item price:";
    cin >> prc;
    item.SetPrice(prc);
    cout << endl;
    cout << "Enter the item quantity:" << endl;
    cin >> qty;
    item.SetQuantity(qty);
    cout << endl;
    cin.ignore();
    //Adds item to list.
    itemList.push_back(item);
    }

    cout << "TOTAL COST" << endl;
    int totalA = itemList[0].GetQuantity() * itemList[0].GetPrice();
    int totalB = itemList[1].GetQuantity() * itemList[1].GetPrice();
    int finalTotal = totalA + totalB;
    cout << itemList[0].GetName() << " " << itemList[0].GetQuantity() << " @ $" << itemList[0].GetPrice() << " = $" << totalA << endl;
    cout << itemList[1].GetName() << " " << itemList[1].GetQuantity() << " @ $" << itemList[1].GetPrice() << " = $" << totalB << endl;
    cout << endl;
    cout << "Total: $" << finalTotal << endl;
    return 0;
}