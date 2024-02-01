class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int index,indexNum,cnt=0;
	for(int i=nums.size()-1; i>0; i--){
		if(nums[i]>nums[i-1]){
			index=i-1;
			indexNum=nums[i-1];
			break;
		}
		else cnt++;
	}
    // cout<<"cnt-"<<cnt<<endl;
	if(cnt==nums.size()-1){
		sort(nums.begin(), nums.end());
		for(auto i: nums){
			cout<<i<<" ";
		}
	}
	else{
		int min = INT_MAX, ans;
	
		for(int i=index+1; i<nums.size(); i++){
			if(nums[i]>indexNum){
				int temp = nums[i]-indexNum;
				if(temp<min){
					min=temp;
					ans=i;
				}
			// cout<<"tempi-"<<temp<<endl;
			}
		}
		int temp= nums[ans];
		nums[ans]=indexNum;
		nums[index]=temp;
        sort(nums.begin()+index+1, nums.end());
		// cout<<temp<<endl;
		for(auto i: nums){
			cout<<i<<" ";
		}
	}
    }
};