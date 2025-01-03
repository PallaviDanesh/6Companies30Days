https://leetcode.com/problems/image-smoother
1.Image Smoother
An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const int m = img.size();
        const int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int ones = 0;
                int count = 0;
                for (int x = max(0, i - 1); x < min(m, i + 2); ++x)
                    for (int y = max(0, j - 1); y < min(n, j + 2); ++y) {
                        ones += img[x][y];
                        ++count;
                    }
                ans[i][j] = ones / count;
            }
        return ans;
    }
};