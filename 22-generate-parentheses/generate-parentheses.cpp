class Solution {
public:

    void output(vector<string> &ans, string s, int open, int close, int total){
        if(open==close && close==total){
            ans.push_back(s);
            return;
        }
        if(open<total){
            s+="(";
            output(ans, s, open+1, close, total);
            s.pop_back();
        }
        if(close<open){
            s+=")";
            output(ans, s, open, close+1, total);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        output(ans, s, 0, 0, n);
        return ans;
    }
};