class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {

        int n = mat.size();
        int m = mat[0].size();

        int rstart = 0;
        int rend = n - 1;

        while (rstart <= rend) {

            int rmid = rstart + (rend - rstart) / 2;

            // Target is exactly the first element of this row
            if (target == mat[rmid][0]) {
                return true;
            }

            // Target is smaller than the first element of this row
            if (target < mat[rmid][0]) {
                rend = rmid - 1;
            }
            else {
                // target > mat[rmid][0]

                // If this is the last possible row,
                // search inside this row
                if (rstart == rend) {

                    int st = 0;
                    int end = m - 1;

                    while (st <= end) {

                        int mid = st + (end - st) / 2;

                        if (mat[rmid][mid] == target) {
                            return true;
                        }
                        else if (mat[rmid][mid] < target) {
                            st = mid + 1;
                        }
                        else {
                            end = mid - 1;
                        }
                    }

                    return false;
                }

                // Check whether target can belong to this row
                if (target < mat[rmid + 1][0]) {

                    // This is the row
                    int st = 0;
                    int end = m - 1;

                    while (st <= end) {

                        int mid = st + (end - st) / 2;

                        if (mat[rmid][mid] == target) {
                            return true;
                        }
                        else if (mat[rmid][mid] < target) {
                            st = mid + 1;
                        }
                        else {
                            end = mid - 1;
                        }
                    }

                    return false;
                }

                // Target belongs to a later row
                rstart = rmid + 1;
            }
        }

        return false;
    }
};