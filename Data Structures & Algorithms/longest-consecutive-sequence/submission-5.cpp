class Solution {

public:
    
    int longestConsecutive(vector<int>& nums) {
        
        int ans=0;
        unordered_set<int> numbers;
        for(auto &num : nums){
            numbers.insert(num);
        }

        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int count = 0;
            if(numbers.count(num-1)) continue;
            count++;
            while(numbers.count(num+1)){
                count++;
                num++;
            }
            ans = max(ans,count);
        }

        return ans;
    }
};
