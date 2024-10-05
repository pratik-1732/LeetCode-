class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m= heights.size(), n= heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        dist[0][0]= 0;
        pq.push({0, {0,0}});

        vector<int> dr= {0, -1, 0, 1}, dc={-1, 0, 1, 0};

        while(!pq.empty()){
            auto it= pq.top();
            int len= it.first;
            int i= it.second.first, j= it.second.second;
            pq.pop();

            if(i==m-1 && j==n-1) return len;

            for(int k=0; k<4; k++){
                int nr= i+dr[k], nc= j+dc[k];
                
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    int diff= abs(heights[i][j]-heights[nr][nc]);
                    if(max(len, diff)<dist[nr][nc]){
                        dist[nr][nc]= max(len, diff);
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};