#ifndef ItemToPurchase_H
#define ItemToPurchase_H
#include <string>

class ItemToPurchase {
    public:
    ItemToPurchase();
    ItemToPurchase(std::string name, std::string description, int price, int quantity);
    void SetName(std::string nm);
    void SetPrice(int prc);
    void SetQuantity(int qty);
    void SetDescription(std::string description);
    std::string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;
    std::string GetDescription() const;
    void PrintItemCost() const;
    void PrintItemDescription() const;
    private:
    std::string name;
    int price;
    int quantity;
    std::string itemDescription;
};

#endif