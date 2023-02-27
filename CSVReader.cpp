//
//  CSVReader.cpp
//  Merklerex
//
//  Created by Admin on 26.02.23.
//

#include <iostream>
#include <fstream>
#include "CSVReader.hpp"

CSVReader::CSVReader() {
    
}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename) {
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile{csvFilename};
    std::string line;
    if (csvFile.is_open()) {
        while (std::getline(csvFile, line)) {
            try {
                OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
                entries.push_back(obe);
            } catch(const std::exception &e) {
                std::cout << "CSVReader::readCSV bad data" << std::endl;
            }
        } // End of while
    }
    std::cout << "CSVReader::readCSV read " << entries.size() << " entries." << std::endl;
    return entries;
}
std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator) {
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(separator, 0);
    do {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) {
            break;
        }
        if (end >= 0) {
            token = csvLine.substr(start, end - start);
        }
        else {
            token = csvLine.substr(start, csvLine.length() - start);
        }
        tokens.push_back(token);
        start = end + 1;
    }  while (end != std::string::npos);
    return tokens;
}
OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens) {
    double price, amount;
    
    if (tokens.size() != 5) { // bad!
        std::cout << "Bad line " << std::endl;
        throw std::exception{};
    }
    try {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    } catch (const std::exception &e) {
        std::cout << "Bad float! " << tokens[3] << std::endl;
        std::cout << "Bad float! " << tokens[4] << std::endl;
        throw;
    }
    OrderBookEntry obe{tokens[0], tokens[1], OrderBookEntry::stringToOrderBookType(tokens[2]), price, amount};
    return obe;
}
