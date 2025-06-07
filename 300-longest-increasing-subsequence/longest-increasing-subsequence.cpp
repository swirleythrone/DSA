class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1,0),curr(n+1,0);
    
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int prev_ind = ind-1 ; prev_ind >= -1 ; prev_ind--){
                int len=next[prev_ind+1];
                if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                   len = max(len,1+next[ind+1]);
                 }
                 curr[prev_ind+1]=len;
            }
            next=curr;
        }
        return next[0];
    }
};