class Solution {
    private:
    void dfs(vector<int> &vis, int node, vector<vector<int>> adj){
        vis[node]=1;
        for(auto i: adj[node]){
            if(!vis[i]){
                dfs(vis, i, adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected[0].size();

        vector<vector<int>> adj(n+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                     adj[i].push_back(j);
                     adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n+1, 0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(vis, i, adj);
            }
        }
        
        return ans;
    }
};