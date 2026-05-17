class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        bool onezero = false;
        int indexzero;
        bool twozero = false;
        int product=1;
        vector<int> res(nums.size(),0);

        for(int i=0; i<nums.size(); i++){
            
            if(nums[i]!=0)
                product *= nums[i];
            else if(onezero == false){
                onezero = true;
                indexzero  = i;
            }
            else{
                twozero = true;
                break;
            }
        }

        if(twozero == true){
            return res;
        }
        else if(onezero == true){
            res[indexzero] = product;
            return res;
        }
        else{
            for(int i=0; i<nums.size(); i++){
                res[i] = product / nums[i];
            }
        }
        return res;;
    }
};
