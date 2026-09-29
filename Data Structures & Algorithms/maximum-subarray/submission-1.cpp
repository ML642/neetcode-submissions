class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int answer = INT_MIN;

        for(int i=0;i<nums.size();i++){
            
            if(sum<0){
                sum=0;
            }
            sum += nums[i];
            answer = max(answer, sum);
        }
        return answer;
    }
};
