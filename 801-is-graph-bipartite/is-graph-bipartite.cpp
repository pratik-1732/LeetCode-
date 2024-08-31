class Solution {
    private:
    bool bfs(vector<vector<int>>& graph, vector<int> &vis, int src){
        vis[src]= 1;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto it: graph[node]){
                if(vis[it]==-1){
                    if(vis[node]==1) vis[it]=0;
                    else vis[it]= 1;
                    q.push(it);
                    // cout<<it<<" "<<vis[it]<<" "<<node<<" "<<vis[node]<<endl;
                }
                else{
                    if(vis[it]==vis[node]) return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1) {
                if(bfs(graph, vis, i)==false) return false;
            }
        }
        return true;
    }
};