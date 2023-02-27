#include <string>
#pragma once

enum class OrderBookType { bid, ask, unknown};

class OrderBookEntry
{
public:
    /** Create a new OrderBookEntry with the price
         *  set to the sent value
         */
    OrderBookEntry(std::string _timestamp, std::string _product,
                   OrderBookType _type, double _price, double _amount);
    
    static OrderBookType stringToOrderBookType(std::string s);
    
    std::string timestamp;
    std::string product;
    OrderBookType type;
    double price;
    double amount;
};
