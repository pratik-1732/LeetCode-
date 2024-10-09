class Solution {
private:
    int timer=1;
private:
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &time, 
    vector<int> &low, vector<int> &vis, vector<vector<int>> &bridges){
        vis[node]= 1;
        low[node]=time[node]=timer++;
        for(auto it: adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it, node, adj, time, low, vis, bridges);
                low[node]= min(low[node], low[it]);
                if(time[node]<low[it]) bridges.push_back({it, node});
            }
            else{
                low[node]= min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> time(n), low(n), vis(n, 0);
        vector<vector<int>> bridges;

        dfs(0, -1, adj, time, low, vis, bridges);

        return bridges;
    }
};