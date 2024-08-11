class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2;
            return;
        } 
        if(n==0){
            return;
        }
        int i=m-1, j=m+n-1, k; 
        for(k=n-1; k>=0; k--){
            if(i<0) break;
            if(nums2[k]>nums1[i]){
                nums1[j]=nums2[k];
                j--;
            }
            else if(nums2[k]==nums1[i]){
                nums1[j]=nums2[k];
                j--; 
                nums1[j]=nums1[i];
                j--; i--;
            }
            else{
                nums1[j]=nums1[i];
                j--; i--;
                k++;
            }
        }
        cout<<j<<endl;
            while(k>=0){
                nums1[j]=nums2[k];
                j--; k--;
            }
    }
};