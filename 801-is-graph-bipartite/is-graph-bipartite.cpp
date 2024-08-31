class Solution {
    private:
    bool dfs(vector<vector<int>>& graph, vector<int> &vis, int node, int color){
        vis[node]= color;
        // cout<<node<<" "<<color<<endl;
        for(auto it: graph[node]){
            if(vis[it]==-1){
                if(vis[node]==1) {
                    if(!dfs(graph, vis, it, 0)) return false;
                }
                else {
                    if(!dfs(graph, vis, it, 1)) return false;
                }
                
            }
            else{
                if(vis[it]==vis[node]) return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> vis(n+1, -1);
        int color= 1;
        for(int i=0; i<n; i++){
            if(vis[i]==-1) {
                if(dfs(graph, vis, i, color)==false) return false;
            }
        }
        return true;
    }
};