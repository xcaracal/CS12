#ifndef ItemToPurchase_H
#define ItemToPurchase_H
#include <string>

class ItemToPurchase {
    public:
    void SetName(std::string nm);
    void SetPrice(int prc);
    void SetQuantity(int qty);
    std::string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;
    private:
    std::string name = "none";
    int price = 0;
    int quantity = 0;
};

#endif