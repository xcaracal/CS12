#include "ShoppingCart.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void PrintMenu(ShoppingCart SC);

int main() {
    string nm;
    string date;
    cout << "Enter customer's name:";
    getline(cin, nm);
    cout << endl;
    cout << "Enter today's date:";
    getline(cin, date);
    cout << endl;
    cout << endl;
    ShoppingCart cart(nm, date);
    
    cout << "Customer name: " << cart.GetCustomerName() << endl;
    cout << "Today's date: " << cart.GetDate() << endl;
    cout << endl;
    PrintMenu(cart);
    return 0;
}

void PrintMenu(ShoppingCart SC) {
    char choice;
    int go = -1;
    while(go == -1){
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:";
    cin >> choice;
    cin.ignore();
    cout << endl;
    while(choice != 'a' && choice != 'd' && choice != 'c' && choice != 'i' && choice != 'o' && choice != 'q'){
        cout <<"Choose an option:"; 
        cin >> choice;
        cin.ignore();
        cout << endl;
        
    }
    if(choice == 'a'){
        ItemToPurchase item;
        string nm;
        string d;
        int prc;
        int qty;
        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, nm);
        cout << "Enter the item description:" << endl;
        getline(cin, d);
        cout << "Enter the item price:" << endl;
        cin >> prc;
        cin.ignore();
        cout << "Enter the item quantity:" << endl;
        cin >> qty;
        cin.ignore();
        cout << endl;
        item.SetName(nm);
        item.SetDescription(d);
        item.SetPrice(prc);
        item.SetQuantity(qty);
        SC.AddItem(item);
    }
    
    if(choice == 'd'){
        string nm;
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove:" << endl;
        getline(cin, nm);
        SC.RemoveItem(nm);
        cout << endl;
    }
    
    if(choice == 'c'){
        ItemToPurchase item;
        string nm;
        int qty;
        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, nm);
        cout << "Enter the new quantity:" << endl;
        cin >> qty;
        cin.ignore();
        item.SetName(nm);
        item.SetQuantity(qty);
        SC.ModifyItem(item);
    }
    
    if(choice == 'i'){
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        SC.PrintDescription();
        cout << endl;
    }
    
    if(choice == 'o'){
        cout << "OUTPUT SHOPPING CART" << endl;
        SC.PrintTotal();
        cout << endl;
    }
    if(choice == 'q'){
        go = 0;
    }
    }
}