class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        if (startColor == color) return image;

        dfs(image, sr, sc, startColor, color);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int r, int c, int startColor, int color) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != startColor) {
            return;
        }

        image[r][c] = color;

        dfs(image, r + 1, c, startColor, color); 
        dfs(image, r - 1, c, startColor, color); 
        dfs(image, r, c + 1, startColor, color); 
        dfs(image, r, c - 1, startColor, color); 
    }
};