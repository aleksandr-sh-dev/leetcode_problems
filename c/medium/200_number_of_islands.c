#include <stdbool.h>

#define ZERO '0'
#define ONE  '1'

void calc_num_islands(char** grid, int gridSize, int gridColSize, bool ***visited, int col, int row) {
    if (row == gridSize) {
        return;
    }

    if (col == gridColSize) {
        return;
    }

    if ((*visited)[row][col] == true) {
        return;
    }

    (*visited)[row][col] = true;

    if (grid[row][col] == ZERO) {
        return;
    }

    // Right
    calc_num_islands(grid, gridSize, gridColSize, visited, col + 1, row);

    // Down
    calc_num_islands(grid, gridSize, gridColSize, visited, col, row + 1);

    // Left
    if (col > 0) {
        calc_num_islands(grid, gridSize, gridColSize, visited, col - 1, row);
    }
    
    // Up
    if (row > 0) {
        calc_num_islands(grid, gridSize, gridColSize, visited, col, row - 1);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int col_size = *gridColSize;
    int islands_num = 0;
    bool **visited = malloc(sizeof(bool *) * gridSize);

    for (int i = 0; i < gridSize; i++) {
        visited[i] = calloc(col_size, sizeof(bool));
    }

    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < col_size; col++) {
            if (grid[row][col] == ONE && !visited[row][col]) {
                islands_num++; 
                calc_num_islands(grid, gridSize, col_size, &visited, col, row); 
            }
        }
    }

    for (int i = 0; i < gridSize; i++) {
        free(visited[i]);
    }

    free(visited);

    return islands_num;
}
