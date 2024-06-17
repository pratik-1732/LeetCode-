class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeros;
        int m= matrix.size();
        int n= matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0) zeros.push_back(make_pair(i,j));
            }
        }
        for(auto i: zeros){
            for(int j=0; j<n; j++){
                matrix[i.first][j]=0;
            }
        }
        for(auto i: zeros){
            for(int j=0; j<m; j++){
                matrix[j][i.second]=0;
            }
        }
        
    }
};