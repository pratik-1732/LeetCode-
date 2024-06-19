#include <bits/stdc++.h>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int diff=INT_MAX, minInd=0, n=nums.size();
        // for(int i=1; i<n; i++){
        //     if(nums[i]>nums[0]){
        //         if(nums[i]-nums[0]<diff){
        //             diff= nums[i]-nums[0];
        //             minInd= i;
        //         }
        //     }
        // }
        int changeInd=-1;
        for(int i=n-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                changeInd=i-1;
                break;
            }
        }
        //cout<<changeInd<<endl;
        if(changeInd==-1){
            sort(nums.begin(), nums.end());
            return;
        }
        diff=INT_MAX;
        int nextInd;
        for(int i=changeInd+1; i<n; i++){
            if(nums[i]>nums[changeInd]){
                if(nums[i]-nums[changeInd]<diff){
                    diff= nums[i]-nums[changeInd];
                    nextInd= i;
                }
            }
        }
        //cout<<nextInd<<endl;
        swap(nums[changeInd], nums[nextInd]);
        sort(nums.begin()+changeInd+1, nums.end());
        
    }
};