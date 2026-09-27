class Solution {
public:
    int maxArea(vector<int>& heights) {
        int answer=0;

        int right=heights.size()-1;
        int left=0;

        while(right>left){
            int left_size = heights[left];
            int right_size = heights[right];
            answer = max(answer,(right-left)*min(right_size,left_size));
            if(right_size>left_size){
                left++;
            }
            else{
                right--;
            }
        }
        return answer;
    }
};
