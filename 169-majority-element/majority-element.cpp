class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n= nums.size();
       int el, cnt=0;
       for(int i=0; i<n; i++){
        if(cnt==0){
            cnt++;
            el=nums[i];
        }
        else if(el==nums[i]) cnt++;
        else cnt--;
       }
       return el;
    }
};