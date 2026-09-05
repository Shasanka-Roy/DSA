class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // rows[i][num] = true if num already exists in row i
        bool rows[9][9] = {};

        // cols[j][num] = true if num already exists in column j
        bool cols[9][9] = {};

        // boxes[k][num] = true if num already exists in box k
        bool boxes[9][9] = {};

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '1';

                // Find which 3x3 box this cell belongs to
                int box = (i / 3) * 3 + (j / 3);

                // Check row, column and box
                if (rows[i][num] ||
                    cols[j][num] ||
                    boxes[box][num]) {
                    return false;
                }

                // Mark as seen
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box][num] = true;
            }
        }

        return true;
    }
};
