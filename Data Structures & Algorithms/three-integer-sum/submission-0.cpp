class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> st;
        
        int i=0,j,k;
        sort(nums.begin(),nums.end());

        while(i<nums.size()-2){
            
            j = i+1;
            k = nums.size()-1;
            
            while(j<k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    st.insert({nums[i] , nums[j] , nums[k]});
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }       
                else {
                    j++;
                }   
            }
            i++;
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
