class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)return-1;
        if(grid[0][0]==0 && n ==1)return 1;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=0;
        q.push({1,{0,0}});
        int drow[8]={-1,-1,0,1,1,1,0,-1};
        int dcol[8]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis=it.first;
            int r = it.second.first;
            int c=it.second.second;
            for(int i = 0 ; i < 8 ; i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=1+dis;
                    if(nrow==n-1 && ncol==n-1)return dis+1;
                    q.push({1+dis,{nrow,ncol}});
                   
                }
                 
            }
        }
        return -1;
        
    }
};