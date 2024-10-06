class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) matrix[i][j]=0;
            }
        }

        for(auto it: edges){
            int from= it[0], to= it[1], wt= it[2];
            matrix[from][to]= wt;
            matrix[to][from]= wt;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    matrix[i][j]= min(matrix[i][j], (matrix[i][k]+matrix[k][j]));
                }
            }
        }

        int maxCnt= n, city= -1, cnt=0;
        for(int i=0; i<n; i++){
            cnt=0;
            for(int j=0; j<n; j++){
                if(matrix[i][j]<=distanceThreshold) cnt++;
            }
            if(cnt<maxCnt){
                maxCnt= cnt;
                city= i;
            }
            else if(cnt==maxCnt) city= max(city, i);
        }

        return city;
    }
};