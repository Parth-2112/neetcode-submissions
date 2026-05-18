class Solution {

public:
    
    int longestConsecutive(vector<int>& nums) {
        
        int ans=0;
        unordered_set<int> st(nums.begin(), nums.end());
        
        for(int s : st){
            if(st.find(s-1) == st.end()){
                int count = 1;
                while(st.find(s + count) != st.end()){
                    count++;
                }
                ans = max(ans, count);
            }            

        }
        return ans;
    }
};
