class Solution {
public:
    bool check(string s, int len, int ind){
        while(len>=ind){
            if(s[len] != s[ind]) return false;
            len--; ind++;
        }
        return true;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        else{
            string temp="";
            while(x>0){
                int y= x%10;
                char ch= (char) y;
                temp+= ch;
                x/=10;
            }
            return check(temp, temp.size()-1, 0);
        }
    }
};