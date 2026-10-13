class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans = 0; 
        int maxi = 0;

        for(int i = prices.size()-1; i>=0; i--){
            maxi = max(prices[i], maxi);
            ans = max(ans, maxi - prices[i]);
        }

        return ans;
    }
};
