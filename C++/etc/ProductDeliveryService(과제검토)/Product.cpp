#include "Product.hh"

Product::Product(std::string name, int price, double weight) {
    //초기화.
    this->name = name;
    this->price = price;
    this->weight = weight;
}

std::string Product::getName() const {
    return this->name;
}

int Product::getPrice() const {
    return this->price;
}

double Product::getWeight() const {
    //무게 반환.
    return this->weight;
}

void Product::updatePrice(int newPrice) {
    //newPrice로 가격 바꿈.
    price = newPrice;
}
        
void Product::changeName(std::string newName) {
    //newName으로 이름 바꿈.
    name = newName;
}

void Product::setWeight(double newWeight) {
    //newWeight으로 무게 변경.
    weight = newWeight;
}

Product::~Product(){

}