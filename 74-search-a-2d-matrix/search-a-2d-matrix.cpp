class Solution {
public:
    bool searchRow(vector<vector<int>>& matrix, int target, int l, int r, int row){
        while(l<=r){
            int mid= l+(r-l)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]>target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size(), m= matrix[0].size();

        int l=0, r= n-1;
        while(l<=r){
            int mid= l+(r-l)/2;
            if(matrix[mid][0]==target || matrix[mid][m-1]==target) return true;
            
            if(matrix[mid][0]<target && matrix[mid][m-1]>target){
                return searchRow(matrix, target, 0, m-1, mid);
            }
            if(matrix[mid][0]>target) r=mid-1;
            if(matrix[mid][m-1]<target) l=mid+1;
        }
        return false;
    }
};