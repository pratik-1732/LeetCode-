class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n=0;
        for(auto it: nums2) n= max(n, it);
        vector<int> ans, temp(n+1, -2); 

        for(int i= nums2.size()-1; i>=0; i--){
            int ele= nums2[i];
            // cout<<ele<<" ";
            if(st.empty()) temp[ele]= -1;
            else{
                while(!st.empty() && st.top()<=ele){
                    st.pop();
                }
                if(st.empty()) temp[ele]= -1;
                else temp[ele]= st.top();
            }
            st.push(ele);
            // cout<<st.top()<<endl;
        }

        for(auto it: nums1){
            ans.push_back(temp[it]);
        }

        return ans;
    }
};