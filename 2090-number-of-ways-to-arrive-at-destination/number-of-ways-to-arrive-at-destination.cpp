class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod= 1e9+7;

        vector<vector<pair<int, int>>> adj(n);
        for(auto i: roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        vector<long long> time(n, 1e12);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        time[0]= 0; ways[0]= 1; pq.push({0, 0});

        while(!pq.empty()){
            auto it= pq.top();
            long long t= it.first;
            long long node= it.second;
            pq.pop();

            for(auto i: adj[node]){
                long long adjNode= i.first, adjt= i.second;
                long long newt= t+adjt;

                if(newt<time[adjNode]){
                    time[adjNode]= newt;
                    pq.push({newt, adjNode});
                    ways[adjNode]= (ways[node]%mod);
                }
                else if(newt==time[adjNode]){
                    ways[adjNode]= (ways[adjNode]+ ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};