class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        unordered_map<int, int> count;
        
        for(const auto num : nums){
            count[num]++;
        }

        vector<pair<int,int>> arr;

        for(auto c : count){
            arr.push_back({c.second, c.first}); 
        }
        sort(arr.rbegin(), arr.rend());

        for(int i=0; i<k; i++){
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};
