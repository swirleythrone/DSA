class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), c(n,1);
        int maxi=1;
        for(int i =1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    c[i]=c[j];
                }
                else if(nums[i]>nums[j] && dp[j]+1==dp[i])c[i]+=c[j];
            }
            maxi=max(dp[i],maxi);
        }
    
        int nos=0;
        for(int i = 0 ; i < n ; i++){
           if(dp[i]==maxi)nos+=c[i];
        }
         return nos;
    }
};