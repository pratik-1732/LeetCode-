#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> check(256, -1);
        int n= s.length();
        int l=0, r=0;
        int cnt=0, ans=0;

        while(r<n){
            char ch= s[r];
            // if(find(check.begin(), check.end(), ch)!=check.end()){
            //     cnt++;
            //     while(l<check.size() && check[l]!=ch){
            //         cnt--;
            //         l++;
            //     }
            //     ans= max(ans, cnt);
            // }
            // else{
            //     check.push_back(ch);
            //     cnt++;
            //     ans= max(ans, cnt);
            // }
            // r++;

            if(check[s[r]]!=-1) {
                if(check[s[r]]>=l){
                    l= check[s[r]]+1;
                }
            }
            cnt= r-l+1;
            ans= max(ans, cnt);
            check[s[r]]= r;
            r++;
        }

        return ans;
    }
};