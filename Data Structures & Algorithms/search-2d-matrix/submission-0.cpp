class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int columns=matrix[0].size();

        int left = 0;
        int right = rows-1;

        while(right>left){
            int mid=left+(right-left+1)/2;
            if(matrix[mid][0]>target){
                right = mid-1;
            }
            else{
                left = mid;
            }
        }
        int row = left;
        left=0;
        right=columns-1;
        while(right>left){
            int mid=(left+right)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            if(matrix[row][mid]<target){
                left = mid+1;
            }
            else{
                right=mid;
            }
        }
        return matrix[row][left]==target;

    }
};
