class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int prod=1,l=nums.size();
	sort(nums.begin(), nums.end());
	int cntNeg=0;
	for(auto i: nums){
		if(i<0) cntNeg++;
	}

	if(cntNeg==0 && cntNeg==1){
		prod*=nums[l-1]*nums[l-2]*nums[l-3];
		return prod;
	}
	else if(cntNeg==2){
		int tem=(nums[0]*nums[1]*nums[l-1]);
		int temp=(nums[l-1]*nums[l-2]*nums[l-3]);
		prod*=tem;
		prod=max(prod,temp);
		return prod;
	}
	else{
		int te=(nums[0]*nums[1]*nums[2]);
		int tem=(nums[0]*nums[1]*nums[l-1]);
		int temp=(nums[l-1]*nums[l-2]*nums[l-3]);
		int ans=max(te,tem);
		prod*=ans;
		prod=max(prod,temp);
		return prod;
	}
    }
};