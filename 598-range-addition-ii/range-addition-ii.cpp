class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // If no operations, the whole matrix has maximum values
        if (ops.empty()) {
            return m * n;
        }
        
        // Find the minimum ai and bi from all operations
        int minRow = m, minCol = n;
        for (const auto& op : ops) {
            minRow = min(minRow, op[0]);
            minCol = min(minCol, op[1]);
        }
        
        // The number of maximum values will be the area of the minRow x minCol submatrix
        return minRow * minCol;
    }
};