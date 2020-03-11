#ifndef ShoppingCart_H
#define ShoppingCart_H

#include <vector>
#include <string>
#include "ItemToPurchase.h"

class ShoppingCart {
    public:
    ShoppingCart();
    ShoppingCart(std::string nm, std::string date);
    std::string GetCustomerName() const;
    std::string GetDate() const;
    int GetNumItemsInCart() const;
    int GetCostOfCart() const;
    void AddItem(ItemToPurchase item);
    void RemoveItem(std::string itemName);
    void ModifyItem(ItemToPurchase item);
    void PrintTotal() const;
    void PrintDescription() const;
    private:
    std::string customerName;
    std::string currentDate;
    std::vector<ItemToPurchase> cartItems;
};

#endif