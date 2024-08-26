class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="", temp="";
        int i=0;
        while(i<=n-1){
            if(s[i]!=' ') temp+=s[i];
            else if(s[i]==' '){
                if(temp!=""){
                    if(ans==""){
                        ans= temp;
                    }
                    else{
                        ans= temp+" "+ans;
                    }
                    temp="";
                }
            }
            i++;
        }
        if(temp!=""){
            if(ans==""){
                ans= temp;
            }
            else{
                ans= temp+" "+ans;
            }
            temp="";
        }
        return ans;
    }
};