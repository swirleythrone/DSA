class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twenty=0;
        for(int i = 0 ; i < bills.size() ; i++){
            if(bills[i]==5)five+=1;
            else if(bills[i]==10){
                if(five){
                    ten+=1;
                    five-=1;
                }else return false;
            }
            else{
                if(ten && five){
                    ten-=1;
                    five-=1;
                }
                else if(five>=3){
                   five-=3;
                }else return false;
            }
        }
        return true;
    }
};