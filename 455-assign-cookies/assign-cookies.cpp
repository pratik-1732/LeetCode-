class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(), m=s.size();
        int gr=0, si=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt=0;
        while(gr<n && si<m){
            if(s[si]>=g[gr]){
                si++;
                gr++;
                cnt++;
            }
            else si++;
        } 
        return cnt;
    }
};