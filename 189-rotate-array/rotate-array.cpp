class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> arr;
        for(auto it: nums){
            arr.push_back(it);
        }
        while(k--){
            int temp= arr.back();
            arr.pop_back();
            arr.push_front(temp);
        }
        for(int i=0; i<nums.size(); i++){
            int temp= arr.front();
            arr.pop_front();
            nums[i]= temp;
        }
    }
};