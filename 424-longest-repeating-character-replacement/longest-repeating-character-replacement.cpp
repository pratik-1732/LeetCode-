class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.length();
        int l=0, r=0;
        vector<int> hash(26, 0);
        int freq=0;
        int ans=0;

        while(r<n){
            hash[s[r]-'A']++;
            freq= max(freq, hash[s[r]-'A']);

            int len= r-l+1;

            if(len-freq > k){
                hash[s[l]-'A']--;
                l++;
            }
            if(len-freq<=k){
                ans= max(ans, r-l+1);
            }

            // cout<<freq<<" "<<ans<<endl;
            r++;
        }

        return ans;
    }
};