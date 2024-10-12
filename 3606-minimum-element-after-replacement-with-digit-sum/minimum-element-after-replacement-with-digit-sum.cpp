class Solution {
public:
    int sumCal(int n, int &sum){
        while(n>0){
            int tens= n%10;
            n/=10;
            sum+= tens;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        vector<int> ans;
        for(auto i: nums){
            int sum=0;
            ans.push_back(sumCal(i, sum));
        }
        sort(ans.begin(), ans.end());

        return ans[0];
    }
};