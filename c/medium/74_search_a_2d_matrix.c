#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 1 && *matrixColSize == 1) {
        if (matrix[0][0] == target) {
            return true;
        } else {
            return false;
        }
    }

    int left_row_idx = 0;
    int right_row_idx = matrixSize - 1;
    int middle_row_idx = 0;

    // Start binary search
    while (left_row_idx <= right_row_idx) {
        middle_row_idx = (left_row_idx + right_row_idx) / 2;
        if (matrix[middle_row_idx][0] == target) {
            return true;
        } else if (matrix[middle_row_idx][0] > target) {
            right_row_idx = middle_row_idx - 1;
            continue;
        } else if (matrix[middle_row_idx][0] < target) {
            // If the last element of chosen subarray still smaller, continue binary search
            if (matrix[middle_row_idx][*matrixColSize - 1] < target) {
                left_row_idx = middle_row_idx + 1;
                continue;
            } else if (matrix[middle_row_idx][*matrixColSize - 1] == target) {
                return true;
            }

            // Binary search inside the chosen subarray
            int left_idx = 0;
            int right_idx = *matrixColSize - 1;
            int middle_idx = 0;
            while (left_idx <= right_idx) {
                middle_idx = (left_idx + right_idx) / 2;
                if (matrix[middle_row_idx][middle_idx] == target) {
                    return true;
                } else if (matrix[middle_row_idx][middle_idx] < target) {
                    left_idx = middle_idx + 1;
                } else {
                    right_idx = middle_idx - 1;
                }
            }
            break;
        }
    }

    return false;
}
