class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                // inside binary serach
                int low = 0;
                int high = m-1;
                while(low<=high){
                    int mid2 = low + (high-low)/2;
                    if(matrix[mid][mid2] == target) return true;
                    else if(matrix[mid][mid2]>target) high = mid2-1;
                    else low = mid2+1;
                }
                return false;
            }
            else if(matrix[mid][0]>target) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};
