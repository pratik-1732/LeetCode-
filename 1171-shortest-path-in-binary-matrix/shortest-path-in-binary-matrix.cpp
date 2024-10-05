class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        // if(m==1 && n==1 && grid[0][0]==0) return 0;

        int m= grid.size(), n= grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0]= 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0,0}});

        vector<int> dr= {-1, -1, -1, 0,  0, 1, 1, 1};
        vector<int> dc= {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty()){
            auto it= q.front();
            int len= it.first;
            int i= it.second.first, j= it.second.second;
            q.pop();

            for(int k=0; k<8; k++){
                int nr= i+dr[k], nc= j+dc[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0 && dist[nr][nc]>len+1){
                    dist[nr][nc]= len+1;
                    q.push({len+1, {nr, nc}});
                }
            }
        }

        if(dist[m-1][n-1]==1e9) return -1;
        else return dist[m-1][n-1];
    }
};