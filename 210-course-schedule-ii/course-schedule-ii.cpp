class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n= prerequisites.size();

        vector<vector<int>> adj(numCourses+1);

        for(int i=0; i<n; i++){
            vector<int> v= prerequisites[i];
            adj[v[1]].push_back(v[0]);
        }

        vector<int> indegree(numCourses);
        for(int i=0; i<numCourses; i++){
            for(auto it: adj[i]) indegree[it]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        vector<int> temp;

        if(ans.size()==numCourses) return ans;
        return temp;
    }
};