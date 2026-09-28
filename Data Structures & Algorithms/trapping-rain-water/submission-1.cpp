class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        vector<int> prefixMax(n,0);
        vector<int> suffixMax(n,0);
        
        int ans = 0;
        int leftmax = height[0];
        int rightmax = height[n - 1];    
    
        for(int i=0; i<n; i++){
            
            if(i==0) {
                prefixMax[i] = 0;
                suffixMax[n-i-1] = 0;
            }
            else {
                prefixMax[i] = leftmax;
                suffixMax[n-i-1] = rightmax;
                leftmax = max(leftmax, height[i]);
                rightmax = max(rightmax, height[n-i-1]);
            }
        }

        for(int i=0; i<n; i++){
            int vol = min(prefixMax[i], suffixMax[i]) - height[i];
            if(vol>0){
                ans+=vol;
            }    
        }

        return ans;

    }
};
