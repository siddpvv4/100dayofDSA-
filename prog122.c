#include <stdio.h>

void dfs(int** image, int m, int n, int r, int c, int originalColor, int newColor) {
    // Boundary check
    if (r < 0 || c < 0 || r >= m || c >= n)
        return;

    // If current pixel is not the original color, stop
    if (image[r][c] != originalColor)
        return;

    // Change color
    image[r][c] = newColor;

    // Explore 4 directions
    dfs(image, m, n, r + 1, c, originalColor, newColor);
    dfs(image, m, n, r - 1, c, originalColor, newColor);
    dfs(image, m, n, r, c + 1, originalColor, newColor);
    dfs(image, m, n, r, c - 1, originalColor, newColor);
}

int** floodFill(int** image, int m, int* imageColSize, int sr, int sc, int color) {
    int originalColor = image[sr][sc];

    // If already same color, no need to process
    if (originalColor == color)
        return image;

    dfs(image, m, imageColSize[0], sr, sc, originalColor, color);

    return image;
}
