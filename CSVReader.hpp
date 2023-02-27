//
//  CSVReader.hpp
//  Merklerex
//
//  Created by Admin on 26.02.23.
//

#ifndef CSVReader_hpp
#define CSVReader_hpp

#include "OrderBookEntry.hpp"
#include <vector>
#include <string>

class CSVReader {
public:
    CSVReader();
    
    static std::vector<OrderBookEntry> readCSV(std::string csvFile);
    
private:
    static std::vector<std::string> tokenise(std::string csvLine, char separator);
    static OrderBookEntry stringsToOBE(std::vector<std::string> tokens);
};

#endif /* CSVReader_hpp */
