#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Goods {
    string Name;
    string Category;
    double Price;
    int QuantityInStock;
public:
    Goods() {
        this->Name = "";
        this->Category = "";
        this->Price = 0;
        this->QuantityInStock = 0;
    }
    Goods(string Name, string Category, double Price, int QuantityInStock) :Name(Name), 
        Category(Category), Price(Price), QuantityInStock(QuantityInStock) {}

    string getName() {
        return this->Name;
    }

    void ChangePrice(double newPrice) {
        this->Price = newPrice;
    }
    void ChangeQuantityInStock(int newQuantity) {
        this->QuantityInStock = newQuantity;
    }

    bool operator==(const string& NameToSearch) const {
        if (this->Name == NameToSearch)
            return true;
        else
            return false;
    }

    friend ostream& operator<<(ostream out, Goods copy) {
        out << "Name: " << copy.Name << "\nCategory: " << copy.Category << "\nPrice: " << copy.Price << "\nQuantity in stock: " << copy.QuantityInStock;
        return out;
    }
};

class Store {
    string Name;
    vector<Goods> goods;
public:
    Store() {
        this->Name = "";
        this->goods;
    }
    Store(string Name, vector<Goods> goods) : Name(Name), goods(goods){}


    void ChangePrice(string& nameToSearch, double newPrice) {
        for_each(this->goods.begin(), this->goods.end(), [&nameToSearch, &newPrice](Goods& item) {if (item.getName() == nameToSearch) {
            item.ChangePrice(newPrice);}});
    }
    void ChangeQuantityInStock(string& nameToSearch, int newQuantity) {
        for_each(this->goods.begin(), this->goods.end(), [&nameToSearch, &newQuantity](Goods& item) {if (item.getName() == nameToSearch) {
            item.ChangeQuantityInStock(newQuantity);
        }});
    }

    friend ostream& operator<<(ostream& out, Store& copy) {
        out << "Name: " << copy.Name;
        out << "\nGoods: ";
        for_each(copy.goods.begin(), copy.goods.end(), [&out](Goods& elem) {out << elem; });
    }
};


int main()
{
    Goods phone("IPhone", "Phone", 500, 10);
    Goods phone2("IPhone2", "Phone2", 1500, 110);
    vector<Goods> goods{ phone, phone2 };
    Store Apple("Apple", goods);
    


    Apple.ChangePrice("IPhone", 1300);
}
