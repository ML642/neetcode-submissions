class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long min_=nums[0];
        long long max_=nums[0];
        long long answer=nums[0];

        for(int i=1;i<nums.size();i++){
            long long previous_max = max_;
            long long previous_min = min_;
            long long x = nums[i];

            max_=max({previous_max*x,x,previous_min*x});
            min_=min({previous_min*x,x,previous_max*x});
            
            answer = max(answer,max_);
        }
        return answer;
    }
};
