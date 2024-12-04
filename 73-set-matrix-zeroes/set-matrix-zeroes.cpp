class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m= matrix.size(), n= matrix[0].size();
        bool firstRow=false, firstCol= false;
        for(int i=0; i<m; i++){
            if(matrix[i][0]==0) firstCol= true;
        }
        for(int i=0; i<n; i++){
            if(matrix[0][i]==0) firstRow= true;
        }
        //set<int> row,col;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    // row.insert(i);
                    // col.insert(j);
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1; i<m; i++){
            if(matrix[i][0]==0){
                for(int j=0; j<n; j++) matrix[i][j]=0;
            }
        }
        for(int i=1; i<n; i++){
            if(matrix[0][i]==0){
                for(int j=0; j<m; j++) matrix[j][i]=0;
            }
        }
        if(firstRow){
            for(int i=0; i<n; i++) matrix[0][i]=0;
        }
        if(firstCol){
            for(int i=0; i<m; i++) matrix[i][0]=0;
        }
        // for(auto it= row.begin(); it!=row.end(); it++){
        //     int num= *it;
        //     for(int i=0; i<n; i++){
        //         matrix[num][i]=0;
        //     }
        // }
        // for(auto it= col.begin(); it!=col.end(); it++){
        //     int num= *it;
        //     for(int i=0; i<m; i++){
        //         matrix[i][num]=0;
        //     }
        // }
    }
};