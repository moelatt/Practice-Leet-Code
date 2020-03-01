#include "main.h"
// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
// You may assume all four edges of the grid are all surrounded by water.
// input: 11000
    //    11000
    //    00100
    //    00011
// Output: 3
class island {
public:
    int numIslands(vector<vector<char> >& grid) {
        if(grid.size() == 0){
            return 0;
        }
        int numIsland = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    numIsland += dfs(grid , i , j);
                }
            }
        }
        return numIsland;
    }
    // using Depth First Search
    int dfs(vector<vector <char> > &grid, int i, int j){ 
        if(i < 0 || i > grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0'){
            return 0;
        }
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        return 1;
    }
};
/*  input:: [["1","1","1","1","0"],
             ["1","1","0","1","0"],
             ["1","1","0","0","0"],
             ["0","0","0","0","0"]] */
// output:: 1`
int main(){
    island is;
    vector<vector<char> > num;
    int result = is.numIslands(num);
    cout << result << endl;
}