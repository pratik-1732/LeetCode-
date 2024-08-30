class Solution {
    private:
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& vis, vector<vector<int>>& distance, queue<pair<pair<int, int>, int>> &q){
        
        vector<int> rv={0, -1, 0, 1};
        vector<int> cv={-1, 0, 1, 0};
        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int d= q.front().second;
            q.pop();

            distance[r][c]= d;

            for(int i=0; i<4; i++){
                int nr= r+rv[i], nc= c+cv[i];
                if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() && vis[nr][nc]==0){
                    if(mat[nr][nc]==0){
                        vis[nr][nc]= 1;
                        q.push({{nr, nc}, 0});
                    }
                    else{
                        vis[nr][nc]= 1;
                        q.push({{nr, nc}, d+1});
                        // distance[nr][nc]= d+1;
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size(), m= mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0) {
                    vis[i][j]=1;
                    q.push({{i,j}, 0});
                }
            }
        }
        bfs(mat, vis, distance, q);
        return distance;
    }
};