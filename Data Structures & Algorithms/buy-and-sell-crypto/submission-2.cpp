class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        for(int i : prices){
            maxProfit = max(maxProfit, i - minPrice);
            minPrice = min(minPrice, i);
        }
        return maxProfit;
    }
};
