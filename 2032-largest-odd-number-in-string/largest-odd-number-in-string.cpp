class Solution {

public:
    string largestOddNumber(string num) {
        ios_base::sync_with_stdio(false);
        int n = num.length();
        int flag=-1;
        for(int i=n-1; i>=0 ; i-- ){
            if((num[i]-'0')%2==1){
                flag=i;
                break;
            }
        }
        return (flag == -1) ? "" : num.substr(0, flag + 1);
    }
};