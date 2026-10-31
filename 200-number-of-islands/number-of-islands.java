class Solution {
    void dfs(int n,int m,char[][] grid,boolean[][] vis,int i,int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1'||vis[i][j]){
            return;
        }
        vis[i][j]=true;
        dfs(n,m,grid,vis,i+1,j);
        dfs(n,m,grid,vis,i-1,j);

        dfs(n,m,grid,vis,i,j+1);

        dfs(n,m,grid,vis,i,j-1);

    }
    public int numIslands(char[][] grid) {
        int islands=0;
        int n=grid.length;
        int m=grid[0].length;
         boolean vis[][]=new boolean[n][m];

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                dfs(n,m,grid,vis,i,j);
                islands++;

                }
            }
         }
         return islands;
    }

}