class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans = 0;
        int buy = 0; 

        for( int sell = 1; sell<prices.size(); sell++){
            
            if(prices[sell] >= prices[buy]){
                ans = max(ans,  prices[sell] - prices[buy]);
            }
            else{
                buy = sell;
            }
        }

        return ans;
    }
};
