class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m= matrix.size(), n= matrix[0].size();
        set<int> row,col;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto it= row.begin(); it!=row.end(); it++){
            int num= *it;
            for(int i=0; i<n; i++){
                matrix[num][i]=0;
            }
        }
        for(auto it= col.begin(); it!=col.end(); it++){
            int num= *it;
            for(int i=0; i<m; i++){
                matrix[i][num]=0;
            }
        }
    }
};