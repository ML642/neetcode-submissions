class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<vector<int>> p;
        queue<vector<int>> a;

        // left -> Pacific
        // right -> Atlantic
        for (int i = 0; i < n; i++) {
            p.push({i, 0});
            pacific[i][0] = true;

            a.push({i, m - 1});
            atlantic[i][m - 1] = true;
        }

        // top -> Pacific
        // bottom -> Atlantic
        for (int j = 0; j < m; j++) {
            pacific[0][j] = true;
            p.push({0, j});

            atlantic[n - 1][j] = true;
            a.push({n - 1, j});
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!p.empty()) {
            int row = p.front()[0];
            int column = p.front()[1];
            p.pop();

            for (int i = 0; i < 4; i++) {
                int new_row = row + dx[i];
                int new_column = column + dy[i];

                if (new_row >= 0 &&
                    new_row < n &&
                    new_column >= 0 &&
                    new_column < m &&
                    heights[new_row][new_column] >= heights[row][column] &&
                    !pacific[new_row][new_column]) {

                    pacific[new_row][new_column] = true;
                    p.push({new_row, new_column});
                }
            }
        }

        while (!a.empty()) {
            int row = a.front()[0];
            int column = a.front()[1];
            a.pop();

            for (int i = 0; i < 4; i++) {
                int new_row = row + dx[i];
                int new_column = column + dy[i];

                if (new_row >= 0 &&
                    new_row < n &&
                    new_column >= 0 &&
                    new_column < m &&
                    heights[new_row][new_column] >= heights[row][column] &&
                    !atlantic[new_row][new_column]) {

                    atlantic[new_row][new_column] = true;
                    a.push({new_row, new_column});
                }
            }
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};