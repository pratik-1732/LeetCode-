class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // int n= flights.size();
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> price(n, 1e9);
        queue<pair<int, pair<int, int>>> pq;

        price[src]= 0;
        pq.push({0, {src, 0}});

        while(!pq.empty()){
            auto it= pq.front();
            int leftk= it.first;
            int cost= it.second.second, node= it.second.first;
            // cout<<node<<" "<<leftk<<" "<<cost<<"- ";
            pq.pop();

            if(leftk>k) continue;
            for(auto i: adj[node]){
                int adjNode= i.first, adjCost= i.second;
                int newCost= cost+adjCost;
                
                if(price[adjNode]>newCost && leftk<=k){
                    price[adjNode]= newCost;
                    //int temp;
                    // if(adjNode==src || adjNode==dst) temp= leftk;
                    // else temp= leftk-1;
                    pq.push({leftk+1, {adjNode, newCost}});
                    // cout<<adjNode<<" "<<temp<<" "<<newCost<<endl;
                }
            }
        }

        if(price[dst]==1e9) return -1;
        else return price[dst];
    }
};