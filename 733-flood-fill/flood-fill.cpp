class Solution {
    private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>> &ans, int code, vector<vector<int>> &vis){
        vis[sr][sc]= 1;
        ans[sr][sc]= color;

        vector<int> row= {-1, 0, 1, 0};
        vector<int> col= {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nRow= sr+row[i], nCol= sc+col[i];
            if(nRow>=0 && nRow<image.size() && nCol>=0 && nCol<image[0].size()){
                if(image[nRow][nCol]==code && !vis[nRow][nCol]){
                    dfs(image, nRow, nCol, color, ans, code, vis);
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans= image;
        int n= image.size(), m= image[0].size();
        
        int code= image[sr][sc];
        vector<vector<int>> vis(n+1, vector<int>(m+1, 0));
        dfs(image, sr, sc, color, ans, code, vis);
        return ans;
    }
};