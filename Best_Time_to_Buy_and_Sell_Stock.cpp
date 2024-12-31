class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int minimun_price = INT_MAX;

        for(int i = 0; i < prices.size(); i++){
            minimun_price = min(prices[i], minimun_price);

            int current_price = prices[i] - minimun_price;

            if(current_price > max_profit){
                max_profit = current_price;
            }
        }

        return max_profit;
    }
};