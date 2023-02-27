#pragma once

#include "OrderBookEntry.hpp"
#include <vector>
#include <string>

class MerkleMain
{
    public:
        MerkleMain() = default;
        /** Call this to start the sim */
        void init();
    private:
        void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        int getUserOption();
        void processUserOption(int userOption);

        std::vector<OrderBookEntry> orders;
};
