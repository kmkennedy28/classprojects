
#include <iostream>

using namespace std;

//create function header
int maxprofit(int prices[12], int funds, int &buyday, int &sellday);

int main()
{
    const int startingfunds = 1000; //money started with
    int prices[12]; // array stores stock prices for 12 days
    int buyday = 0, sellday = 0; //to store what day to buy and sell

    //get user inputed price of the stock from each day seperated by a space
    cout << "Please type the 12-day price history of the stock: \n";
    cin >> prices[0] >> prices[1] >> prices[2] >> prices[3] >> prices[4] >> prices[5] >> prices[6] >> prices[7] >> prices[8] >> prices[9] >> prices[10] >> prices[11];

    //get the calculated max profit 
    int max = maxprofit(prices, startingfunds, buyday, sellday);
    //subtract the starting amount from the max for the profit
    max -= startingfunds;

    //Print the max profit and which days to buy and sell
    if (max == 0) {
        cout << "Max Profit: " << max << "." << endl;
    }
    else {
        cout << "Max Profit: " << max << "." << endl;
        cout << "Best Strategy: buy on day " << (buyday + 1) << ", sell on day " << (sellday + 1) << ".";
    }
}

//function calculates the max profit from the prices and intial funds
int maxprofit(int prices[12], int funds, int& buyday, int& sellday){
    int maxp = 0; //placeholder for the max price
    int currentp; //current profit
    int stocksbought; //how many stocks to buy

    //loop through the days
    for (int i = 0; i < 12; i++) {
        stocksbought = funds / prices[i]; //number of stocks to be bought from the price for that day
        for (int j = (i + 3); j < 12; j++) { //3 day later through the end of the week
            currentp = stocksbought * prices[j]; //the profit from the day
            //if the profit is higher than the max 
            if (currentp > maxp) {
                //max, buy, and sell are updates
                maxp = currentp;
                buyday = i;
                sellday = j;
            }
        }
    }
    return maxp;
}
