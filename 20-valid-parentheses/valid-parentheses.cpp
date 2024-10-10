class Solution {
public:
    bool isValid(string s) {
        int n= s.length();
        stack<char> st;
        vector<char> temp= {'(', '[', '{', ')', ']', '}'};
        int cnt=0;
        for(auto i: s){
            for(int j=3; j<6; j++){
                if(i==temp[j]){
                    cnt++;
                    if(st.empty()) return false;
                    char atTop= st.top();

                    if(atTop==temp[j-3]) st.pop();
                    else cnt--;
                }
            }
            if(cnt==0) st.push(i);
            else cnt=0;
        }
        if(st.empty()) return true;
        else return false;
    }
};