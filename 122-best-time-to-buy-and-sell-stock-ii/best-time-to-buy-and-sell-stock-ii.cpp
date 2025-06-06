class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2,0),curr(2,0);

        next[0]=next[1]=0;

        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit=0;

               if(buy){
                 profit= max(-prices[ind]+next[0],next[1]);
               }
               else{
                 profit= max(prices[ind]+next[1],next[0]);
                }
                curr[buy] = profit;
            }
            next=curr;
        }
         return next[1];
    }
};