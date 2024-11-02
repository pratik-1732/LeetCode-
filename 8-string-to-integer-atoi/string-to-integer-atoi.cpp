class Solution {
public:
    void output(string &s, int ind, long long &ans, int &sign, int &cnt){
        // cout<<s[ind]<<" "<<ans<<" "<<sign<<" "<<cnt<<endl;
        if(ind>=s.length()) return;
        if(s[ind]=='-' && cnt==0) {
            sign= -1; cnt++;
            output(s, ind+1, ans, sign, cnt);
        }
        if(s[ind]=='+' && cnt==0) {
            cnt++;
            output(s, ind+1, ans, sign, cnt);
        }
        if(s[ind]>='0'&&s[ind]<='9'){
            ans= ans*10+(s[ind]-'0');
            cnt++;
            if(ans>INT_MAX && sign==-1){
                ans= INT_MIN;
                return;
            }
            else if(ans>INT_MAX && sign==1){
                ans= INT_MAX;
                return;
            }
        }
        else{
            // cout<<"inside- "<<ans<<" "<<sign<<endl;
            ans*=sign;
            sign=1;
            return;
        }
        output(s, ind+1, ans, sign, cnt);
    }
    int myAtoi(string s) {
        int n= s.length();
        long long ans=0;
        int ind=0;
        int sign=1;
        int cnt=0;
        while(ind<n && s[ind]==' '){
            ind++;
        }
        output(s, ind, ans, sign, cnt);
        return ans;
    }
};