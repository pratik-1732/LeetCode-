class Solution {
public:
    // bool checkCycle(vector<vector<int>>& adj, int numCourses, int currNode, vector<int>& visited, vector<int>& pathVis){
    //     vector<int> stack;
    //     stack.push_back(currNode);

    //     while(!stack.empty()){
    //         int node = stack.back();
    //         stack.pop_back();

    //         if(!visited[node]){
    //             visited[node] = 1;
    //             pathVis[node] = 1;
    //             stack.push_back(node);

    //             for (auto v: adj[node]){
    //                 if (!visited[v]){
    //                     stack.push_back(v);
    //                 }
    //                 if(pathVis[v]){
    //                     return true;
    //                 }
    //             }
    //         }
    //         else if(pathVis[node]){
    //             pathVis[node] = 0;
    //         }
    //     }

    //     return false;
    // }

    bool checkCycle(vector<vector<int>>& adj, int currNode, vector<int>& visited, vector<int>& pathVis){
        visited[currNode] = 1;
        pathVis[currNode] = 1;

        for(auto v: adj[currNode]){
            if (!visited[v]){
                if(checkCycle(adj, v, visited, pathVis)){
                    return true;
                }
            }
            else if (pathVis[v]){
                return true;
            }
        }
        pathVis[currNode] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(auto v: prerequisites){
            adj[v[0]].push_back(v[1]);
        }
        
        for(int i=0; i<numCourses; i++){
            if (!visited[i]){
                if(checkCycle(adj, i, visited, pathVis)==true){
                    return false;
                }
            }
        }

        return true;
    }
};