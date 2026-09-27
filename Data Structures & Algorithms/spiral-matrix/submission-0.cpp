class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;

        int right = matrix[0].size()-1;
        int left = 0;
        int bottom = matrix.size()-1;
        int top = 0;


        while(top<=bottom && right>=left){
           
            for(int j=left;j<=right;j++){
                answer.push_back(matrix[top][j]);
            }
            top++;

            for(int i=top;i<=bottom;i++){
                answer.push_back(matrix[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    answer.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    answer.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return answer;
    }
};
