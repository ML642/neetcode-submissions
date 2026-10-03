class Solution {
public:
    int jump(vector<int>& nums) {   
        int x = 0;
        int answer = 0;

        if(nums.size()==1)return 0;
        while(x<nums.size()){
            if(x+nums[x] >= nums.size()-1){
                return answer+1;
            }

            int max = INT_MIN;
            int index = -1;
            for(int i=x+1;i<=x+nums[x] && i<nums.size();i++){
        
                if(max < nums[i] + i ){
                    max = nums[i] + i ;
                    index = i;
                }
            }
            answer++;
            
            if(index == -1 || max == 0){
                return -1;
            }
            x = index;
        }
        return -1;

    }
};
