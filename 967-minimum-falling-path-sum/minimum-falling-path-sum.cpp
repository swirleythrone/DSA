class Solution {
public:
    

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j = 0 ; j < n ; j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i = 1 ; i< n ; i++){
            for(int j = 0 ; j < n ; j++){
                 int up = matrix[i][j]+dp[i-1][j];
                 int dl=matrix[i][j];
                 if(j-1>=0)dl+=dp[i-1][j-1];
                 else dl=1e8;
                 int dr=matrix[i][j];
                 if(j+1<n)dr+=dp[i-1][j+1];
                 else dr=1e8;
                
                
                dp[i][j]=min(up,min(dl,dr));
            }
        }
        int mini=1e8;
        for(int j = 0 ; j < n ; j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};