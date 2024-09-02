class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n= graph.size();
        vector<vector<int>> revadj(n);
        vector<int> indegree(n, 0);

        for(int i=0; i<n; i++){
            for(auto it: graph[i]){
                indegree[i]++;
                revadj[it].push_back(i);
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i]==0) q.push(i);
        }

        vector<int> ans;
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            // cout<<node<<endl;
            ans.push_back(node);

            for(auto it: revadj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};