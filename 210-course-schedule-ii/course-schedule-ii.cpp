class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<int> &vis, vector<int> &pathvis, int node, vector<int> &ans){
        vis[node]= 1;
        pathvis[node]= 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(adj, vis, pathvis, it, ans)) return true;
            }
            else{
                if(pathvis[it]) return true;
            }
        }
        ans.push_back(node);
        pathvis[node]= 0;
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);

        vector<vector<int>> adj(numCourses+1);
        for(int i=0; i<prerequisites.size(); i++){
            vector<int> v= prerequisites[i];
            adj[v[1]].push_back(v[0]);
        }
        vector<int> ans;
        vector<int> empty;
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(adj, vis, pathvis, i, ans)) return empty;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};