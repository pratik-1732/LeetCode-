class disjointSet{
    
public:
    vector<int> parent, size, rank;
    disjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++) parent[i]= i;
    }

    int findUParent(int node){
        if(parent[node]==node) return node;

        return parent[node]= findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u= findUParent(u);
        int ulp_v= findUParent(v);
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
        int ulp_u= findUParent(u);
        int ulp_v= findUParent(v);
        if(ulp_u==ulp_v) return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]= ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]= ulp_u;
        }
        else{
            parent[ulp_v]= ulp_u;
            rank[ulp_v]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int m= stones.size();
        int totalRow=0, totalCol=0;
        for(auto it: stones){
            int row= it[0], col= it[1];
            totalRow= max(totalRow, row);
            totalCol= max(totalCol, col);
        }
        int n= totalRow+totalCol+1;

        disjointSet ds(n+1);

        unordered_map<int, int> stoneNodes;
        for(auto it: stones){
            int row= it[0], col= it[1];
            int modifiedCol= totalRow+col+1;
            ds.unionByRank(row, modifiedCol);
            stoneNodes[row]=1;
            stoneNodes[modifiedCol]=1;
        }
        // set<int> uniqueParents;
        int cnt=0;
        for(auto it: stoneNodes){
            // int ulParent= ds.findUParent(it.first);
            // uniqueParents.insert(ulParent);
            if(ds.findUParent(it.first)==it.first) cnt++;
        }
        // int ans= m-uniqueParents.size();
        int ans= m-cnt;
        // cout<<m<<" "<<ans<<endl;
        if(ans==0) return 0;
        else return ans;
    }
};