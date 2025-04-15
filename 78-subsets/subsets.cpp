class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int subset=1<<n;
        for(int i = 0 ;i < subset ; i++){
            vector<int> list;
            for(int j = 0 ; j<n ; j++){
                if(i&(1<<j))list.push_back(nums[j]);
            }
            ans.push_back(list);
        }
        return ans;

    }
};