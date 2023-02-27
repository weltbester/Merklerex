#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "OrderBookEntry.hpp"
#include "MerkleMain.hpp"
#include "CSVReader.hpp"

// Test functions
double computeAveragePrice(std::vector<OrderBookEntry> &entries) {
    double sum = 0.0;
    for (OrderBookEntry &e : entries) {
        sum += e.price;
    }
    return sum / entries.size();
}

double computeLowPrice(std::vector<OrderBookEntry> &entries) {
    double lowest = entries[0].price;
    for (OrderBookEntry &e : entries) {
        if (e.price < lowest) {
            lowest = e.price;
        }
    }
    return lowest;
}

double computeHighPrice(std::vector<OrderBookEntry> &entries) {
    double highest = entries[0].price;
    for (OrderBookEntry &e : entries) {
        if (e.price > highest) {
            highest = e.price;
        }
    }
    return highest;
}

double computePriceSpread(std::vector<OrderBookEntry> &entries) {
    double avg = computeAveragePrice(entries);
    double sumSquares = 0.0;
    for (OrderBookEntry &e : entries) {
        sumSquares += pow((e.price - avg), 2);
    }
    return sqrt((sumSquares / (entries.size() - 1)));
}

int main()
{
    
    CSVReader::readCSV("/Users/admin/Documents/Programming/Test/20200317.csv");
   
    return 0;
}
