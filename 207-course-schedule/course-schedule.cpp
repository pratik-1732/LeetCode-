class Solution {
    private:
    bool dfs(int node, vector<vector<int>> adj, vector<int> &vis){
       vis[node] = 1;
       for(auto i: adj[node]){
            if(vis[i] == 0){
                if(dfs(i,adj,vis)) return true;
            }
            else if(vis[i] == 1){
                // cout<<"vis[node]"<<node<<endl;;
                return true;
            }
       }
       vis[node] = 2;
       return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n= prerequisites.size();
        vector<int> vis(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<n; i++){
            int a = prerequisites[i][0], b = prerequisites[i][1];
            adj[b].push_back(a);
        }
       
        // cout<<i<<endl;
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis)){
                    return false;
                }       
            }
        }
        return true;
    }
};