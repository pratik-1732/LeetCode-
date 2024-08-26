class Solution {
public:
    string reverseWords(string s) {
        vector<string> check;
        string str="";
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' ') str+=s[i];
            else{
                if(str.size()!=0){
                    check.push_back(str);
                    str="";
                }
            }
        }
        if(str.size()!=0) check.push_back(str);
        reverse(check.begin(), check.end());
        string ans="";
        for(auto i: check) {
            ans+=i;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};