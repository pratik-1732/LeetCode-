class Solution {
public:
    string convertToTitle(int columnNumber) {
        string temp="";
        while(columnNumber>0){
            columnNumber--;
            int ans= columnNumber%26;
            //if(ans>0) ans--;
            temp+=(ans+'A');
            columnNumber/=26;
            
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};