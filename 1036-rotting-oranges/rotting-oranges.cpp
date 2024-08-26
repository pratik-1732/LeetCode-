class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int vis[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) vis[i][j]=0;
        }
        queue<pair<pair<int, int>, int>> rotten;
        int fresh=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    rotten.push({{i,j},0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==0) vis[i][j]=0;
                if(grid[i][j]!=0) fresh++;
            }
        }
        int maxTime=0, cnt=0;
        int r[]={-1, 0, 1, 0};
        int c[]= {0, 1, 0, -1};
        while(!rotten.empty()){
            int row=  rotten.front().first.first;
            int col=  rotten.front().first.second;
            int time=  rotten.front().second;
            rotten.pop();

            maxTime= max(maxTime, time);
            cnt++;
            // cout<<row<<" "<<col<<" "<<time<<endl;
            for(int i=0; i<4; i++){
                int x=row+r[i], y=col+c[i];
                // cout<<x<<" "<<y<<endl;
                if(x>=0 && x<n && y>=0 && y<m && vis[x][y]!=2 && grid[x][y]==1){
                    vis[x][y]=2;
                    rotten.push({{x,y}, time+1});
                    // cout<<x<<" "<<y<<endl;
                    // cnt++;
                }
            }
        }
        // cout<<cnt<<" "<<fresh<<endl;
        if(cnt!=fresh) return -1;
        return maxTime;
    }
};