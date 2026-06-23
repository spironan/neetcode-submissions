class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int count = 0;
        int n = grid.size();
        int m = grid.front().size();

        for(int i = 0; i < n; ++i) {
            grid[i].insert(grid[i].begin(), 0);
            grid[i].emplace_back(0);
        }
        grid.insert(grid.begin(), vector(m + 2, 0));
        grid.emplace_back(vector(m + 2, 0));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i+1][j+1]) {
                    // perimeter += 4 - 
                    //     (
                    //         grid[i + 1][j] + grid[i][j + 1] +
                    //         grid[i + 2][j + 1] + grid[i + 1][j + 2]
                    //     );
                    perimeter += 4 - 2 * grid[i][j + 1] - 2 * grid[i + 1][j];
                }
            }
        }
        return perimeter;
    }
};