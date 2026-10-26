void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 1) {
        return;
    }

    // Transponse
    for (int row = 0; row < matrixSize; row++) {
        for (int col = row + 1; col < matrixSize; col++) {
            int temp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = temp;
        }
    }

    // Revert horizontally
    for (int row = 0; row < matrixSize; row++) {
        int left = 0;
        int right = matrixSize - 1;
        while (left < right) {
            int temp = matrix[row][left];
            matrix[row][left] = matrix[row][right];
            matrix[row][right] = temp;
            left++;
            right--;
        }
    }
}