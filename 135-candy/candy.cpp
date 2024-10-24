class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans=0;
        int n= ratings.size();
        vector<int> cnt(n,1);
        for(int i=1; i<n; i++){
          if(ratings[i]>ratings[i-1])  cnt[i]= cnt[i-1]+1;
        }
         for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]) {
                if(cnt[i]<=cnt[i+1]) cnt[i]= cnt[i+1]+1;
            }
         }
         for(auto i: cnt){
           ans+= i;
         }

         return ans;
    }
};