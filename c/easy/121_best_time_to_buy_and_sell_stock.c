int maxProfit(int* prices, int pricesSize) {
    int max_profit = 0;
    int curr_profit = 0;
    int curr_max_idx = (pricesSize - 1);
    
    for (int i = (pricesSize - 1); i > 0; i--) {
        curr_profit = prices[curr_max_idx] - prices[i - 1];
        if (curr_profit < 0) {
            curr_max_idx = (i - 1);
        } else {
            if (curr_profit > max_profit) {
                max_profit = curr_profit;
            }   
        }
    }

    return max_profit;
}
