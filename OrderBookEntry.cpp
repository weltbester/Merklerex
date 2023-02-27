#include "OrderBookEntry.hpp"

OrderBookEntry::OrderBookEntry(std::string _timestamp, std::string _product,
                   OrderBookType _type, double _price, double _amount)
        : timestamp(_timestamp), product(_product), type(_type), price(_price), amount(_amount)
{

}

OrderBookType OrderBookEntry::stringToOrderBookType(std::string s) {
    if (s == "ask") {
        return OrderBookType::ask;
    }
    if (s == "bid") {
        return OrderBookType::bid;
    }
    return OrderBookType::unknown;
}
