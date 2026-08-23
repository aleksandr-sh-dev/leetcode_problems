#include <stdbool.h>

void max_area_of_island(int** grid, int gridSize, int gridColSize, bool ***visited, int *cur_area, int col, int row) {
    if (row == gridSize) {
        return;
    }

    if (col == gridColSize) {
        return;
    }

    if ((*visited)[row][col] == true) {
        return;
    }

    if (grid[row][col] == 1) {
        (*cur_area)++;
    }

    (*visited)[row][col] = true;

    if (grid[row][col] == 0) {
        return;
    }

    // Right
    max_area_of_island(grid, gridSize, gridColSize, visited, cur_area, col + 1, row);

    // Down
    max_area_of_island(grid, gridSize, gridColSize, visited, cur_area, col, row + 1);

    // Left
    if (col > 0) {
        max_area_of_island(grid, gridSize, gridColSize, visited, cur_area, col - 1, row);
    }
    
    // Up
    if (row > 0) {
        max_area_of_island(grid, gridSize, gridColSize, visited, cur_area, col, row - 1);
    }
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int col_size = *gridColSize;
    int max_area = 0;
    bool **visited = malloc(sizeof(bool *) * gridSize);

    for (int i = 0; i < gridSize; i++) {
        visited[i] = calloc(col_size, sizeof(bool));
    }

    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < col_size; col++) {
            if (!visited[row][col]) {
                int area = 0;
                max_area_of_island(grid, gridSize, col_size, &visited, &area, col, row);
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
    }

    for (int i = 0; i < gridSize; i++) {
        free(visited[i]);
    }

    free(visited);

    return max_area;
}
