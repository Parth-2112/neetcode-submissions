class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapp;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            int req = target-nums[i];
            if(mapp.find(req) != mapp.end()){
                ans.push_back(mapp[req]);
                ans.push_back(i);
                break;
            }
            mapp[nums[i]] = i;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
