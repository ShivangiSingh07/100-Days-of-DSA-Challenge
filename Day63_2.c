/*
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
Return the modified image after performing the flood fill.
*/
#include <stdio.h>
#include <stdlib.h>

void fill(int** image, int m, int n, int r, int c, int oldColor, int newColor) {
    if (r < 0 || r >= m || c < 0 || c >= n) return;
    if (image[r][c] != oldColor) return;
    image[r][c] = newColor;
    fill(image, m, n, r+1, c, oldColor, newColor);
    fill(image, m, n, r-1, c, oldColor, newColor);
    fill(image, m, n, r, c+1, oldColor, newColor);
    fill(image, m, n, r, c-1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int oldColor = image[sr][sc];
    if (oldColor != color) {
        fill(image, imageSize, *imageColSize, sr, sc, oldColor, color);
    }
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = *imageColSize;
    }
    return image;
}

int main() {
    int m = 3, n = 3;
    int arr[3][3] = {{1,1,1},{1,1,0},{1,0,1}};
    int* image[3];
    for (int i = 0; i < m; i++) image[i] = arr[i];
    int returnSize;
    int* returnColumnSizes;
    int** result = floodFill(image, m, &n, 1, 1, 2, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free(returnColumnSizes);
    return 0;
}
