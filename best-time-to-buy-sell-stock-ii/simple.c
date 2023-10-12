#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    int min = prices[0];
    int max = prices[0];
    for (int i = 0; i< pricesSize; i++) {
        if (min > prices[i]) {
            min = prices[i];
        } else {
            max = prices[i];
            profit += max-min;
            min = max;
        }
    }
    return profit;
}

int main(int argc, char const *argv[])
{
    int nums[] = {7,1,5,3,6,4};
    int k = maxProfit(nums, 6);
    printf("--> maxProfit = %d\n", k);
    return 0;
}