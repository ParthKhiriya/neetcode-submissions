class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int right = n-1;
        int row = -1;

        while(left <= right) {
            int mid = left + ((right-left)/2);
            if(matrix[mid][0] == target) {
                return true;
            } else if(matrix[mid][0] < target) {
                row = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if(row == -1) return false;

        left = 0;
        right = m-1;

        while(left <= right) {
            int mid = left + ((right-left)/2);
            if(matrix[row][mid] == target) {
                return true;
            } else if(matrix[row][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
