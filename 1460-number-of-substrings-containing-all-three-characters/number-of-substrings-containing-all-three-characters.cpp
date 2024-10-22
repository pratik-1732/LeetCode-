class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.length();
        int ans=0;

        vector<int> count(3, -1);

        for(int i=0; i<n; i++){
           count[s[i]-'a']= i;
           if(count[0]!=-1 && count[1]!=-1 && count[2]!=-1){
                int mini= min(count[0], min(count[1], count[2]));
                ans+= mini+1;
           }
        }

        return ans;
    }
};