/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int **res = malloc(sizeof(int *) * (*matrixColSize));

    for (int i = 0; i < (*matrixColSize); i++) {
        res[i] = malloc(sizeof(int) * matrixSize);
    }

    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < (*matrixColSize); col++) {
            res[col][row] = matrix[row][col];
        }
    }

    *returnSize = *matrixColSize;
    *returnColumnSizes = malloc(sizeof(int) * (*matrixColSize));

    for (int i = 0; i < *matrixColSize; i++) {
        (*returnColumnSizes)[i] = matrixSize;
    }

    return res;
}