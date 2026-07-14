class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = n - 1;
            while (left <= right) {
                if (left == right) {
                    image[i][left] = 1 - image[i][left];
                } else if (image[i][left] == image[i][right]) {
                    image[i][left] = 1 - image[i][left];
                    image[i][right] = image[i][left];
                }
                left++;
                right--;
            }
        }
        return image;
    }
};