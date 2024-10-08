class disjointSet{
public:
    vector<int> parent, size, rank;

    disjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++) parent[i]= i;
    }

    int findParent(int node){
        if(parent[node]==node) return node;

        return parent[node]= findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u= findParent(u);
        int ulp_v= findParent(v);

        if(ulp_u==ulp_v) return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]= ulp_v;
            size[ulp_v]+= size[ulp_u];
        }
        else{
            parent[ulp_v]= ulp_u;
            size[ulp_u]+= size[ulp_v];
        }
    }

    void unionByRank(int u, int v){
        int ulp_u= findParent(u);
        int ulp_v= findParent(v);

        if(ulp_u==ulp_v) return;

        if(rank[ulp_u]<rank[ulp_v]) parent[ulp_u]= ulp_v;
        else if(rank[ulp_u]>rank[ulp_v]) parent[ulp_v]= ulp_u;
        else{
            parent[ulp_v]= ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointSet ds(n);
        int extra=0, cnt=0;

        for(auto it: connections){
            int u= it[0], v= it[1];
            if(ds.findParent(u)==ds.findParent(v)) extra++;
            else ds.unionByRank(u,v);
        }

        for(int i=0; i<n; i++){
            if(ds.parent[i]==i) cnt++;
        }

        // cout<<extra<<" "<<cnt<<endl;
        int ans= cnt-1;

        if(ans<=extra) return ans;
        else return -1;
    }
};