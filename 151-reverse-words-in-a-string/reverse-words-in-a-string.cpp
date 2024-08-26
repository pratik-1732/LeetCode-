class Solution {
public:
    string reverseWords(string s) {
        stack<string> check;
        string str="";
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' ') str+=s[i];
            else{
                if(str.size()!=0){
                    check.push(str);
                    str="";
                }
            }
        }
        if(str.size()!=0) check.push(str);
        string ans="";
        while(!check.empty()){
            ans+= check.top();
            check.pop();
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};