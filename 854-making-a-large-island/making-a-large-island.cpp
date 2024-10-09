class disjointSet{
    
public:
    vector<int> parent, size;
    disjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
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
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        disjointSet ds(n*n);

        vector<int> dr= {0, -1, 0, 1};
        vector<int> dc= {-1, 0, 1, 0};
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c]==1){
                    for(int i=0; i<4; i++){
                        int newr= r+dr[i], newc= c+dc[i];
                        if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                            int nodeNo= r*n+c;
                            int adjNodeNo= newr*n+newc;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }

        int cnt=0, ans=0;
        for(int i=0; i<n*n; i++){
            int temp= ds.findUParent(i);
            ans= max(ans, ds.size[temp]);
        }

        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c]==0){
                    set<int> uniqueAdjNode;
                    cnt=0;
                    for(int i=0; i<4; i++){
                        int newr= r+dr[i], newc= c+dc[i];
                        if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                            int nodeNo= r*n+c;
                            int adjNodeNo= newr*n+newc;
                            int ulParent= ds.findUParent(adjNodeNo);
                            uniqueAdjNode.insert(ulParent);
                        }
                    }
                    for(auto it=uniqueAdjNode.begin(); it!=uniqueAdjNode.end(); it++){
                        int num= *it;
                        cnt+= ds.size[num];
                    }
                    cnt++;
                    ans= max(ans, cnt);
                }
            }
        }

        return ans;
    }
};