class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = numbers.size()-1;
        int left = 0;

        while(right>left){
            if(numbers[right]+numbers[left]==target){
                return {left+1,right+1};
            }
            if(numbers[right]+numbers[left]>target){
                right--;
            }
            else{
                left++;
            }
        }
        return {-1};
    }
};
