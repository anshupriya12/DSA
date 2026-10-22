class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int originalColor, int color) {
        int rows = image.size();
        int cols = image[0].size(); 

        //check boundaries
        if ( i < 0 || i >= rows || j < 0 || j >= cols) {
            return;
        }

        //stop if pixel doesn't have original color
        if (image[i][j] != originalColor) {
            return;
        }

        image[i][j] = color;

        //visit the four neighbours
        dfs(image, i-1, j, originalColor, color); // up
        dfs(image, i+1, j, originalColor, color); // down

        dfs(image, i, j-1, originalColor, color); //left
        dfs(image, i, j+1, originalColor, color); //right
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //given i/p is an adjacency matrix
        //will use dfs

        int originalColor = image[sr][sc];

        if (originalColor == color) {
            return image;
        }

        dfs(image, sr, sc, originalColor, color);

        return image;

    }
};