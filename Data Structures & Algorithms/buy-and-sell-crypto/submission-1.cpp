class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans = 0; 
        int min = 0;

        for( int sell = 1; sell<prices.size(); sell++){
            
            if(prices[sell]<prices[min]){
                min = sell;
            }
            else{
                ans = max(ans, prices[sell] - prices[min]);
            }    
        }

        return ans;
    }
};
