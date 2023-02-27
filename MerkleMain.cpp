#include "MerkleMain.hpp"
#include <iostream>
#include <vector>
#include <string>

void MerkleMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue
    std::cout << "6: Continue " << std::endl;

    std::cout << "============== " << std::endl;
}

void MerkleMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void MerkleMain::printMarketStats()
{
    std::cout << "Market looks good. " << std::endl;
}

void MerkleMain::enterOffer()
{
    std::cout << "Make an offer - enter the amount " << std::endl;
}

void MerkleMain::enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkleMain::printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}

void MerkleMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
}

int MerkleMain::getUserOption()
{
    int userOption;

    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkleMain::processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1) // bad input
    {
        printHelp();
    }
    if (userOption == 2) // bad input
    {
        printMarketStats();
    }
    if (userOption == 3) // bad input
    {
        enterOffer();
    }
    if (userOption == 4) // bad input
    {
        enterBid();
    }
    if (userOption == 5) // bad input
    {
        printWallet();
    }
    if (userOption == 6) // bad input
    {
        gotoNextTimeframe();
    }
}

/** Load up some dummy data for now */
void MerkleMain::loadOrderBook()
{
    std::vector<OrderBookEntry> orders;

    orders.push_back(OrderBookEntry{"2020/03/17 17:01:24.884492",
                                    "BTC/USDT",
                                    OrderBookType::bid,
                                    0.02,
                                    1000});
    orders.push_back(OrderBookEntry{"2020/03/17 17:01:24.884492",
                                    "BTC/USDT",
                                    OrderBookType::bid,
                                    0.02,
                                    2000});
}

/** Your main function should call this */
void MerkleMain::init()
{
    loadOrderBook();
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}
