int get_box_num(int row, int col) {
    return (((row / 3) * 3) + (col / 3));
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    bool nums_cols[9][9]; // 9 cols and 9 nums
    bool nums_rows[9][9]; // 9 rows and 9 nums
    bool nums_boxes[9][9]; // 9 boxes and 9 nums

    memset(nums_cols, false, sizeof(nums_cols));
    memset(nums_rows, false, sizeof(nums_rows));
    memset(nums_boxes, false, sizeof(nums_boxes));

    // r - row, c - col
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                continue;
            }

            int box_num = get_box_num(r, c);
            int num = board[r][c] - '0' - 1; // 0 - 9

            if (nums_cols[c][num] == false) {
                nums_cols[c][num] = true; // first time seen this number
            } else {
                return false; // seen this number
            }

            if (nums_rows[r][num] == false) {
                nums_rows[r][num] = true;
            } else {
                return false;
            }

            if (nums_boxes[box_num][num] == false) {
                nums_boxes[box_num][num] = true;
            } else {
                return false;
            }
        }
    }

    return true;
}