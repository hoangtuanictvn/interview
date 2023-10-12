int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    int min = prices[0];
    for (int i = 0; i< pricesSize; i++) {
        int currentPrice = prices[i];
        if (min > currentPrice) {
            min = currentPrice;
        }
        if (profit < currentPrice - min) {
            profit = currentPrice - min;
        }
    }
    return profit;
}