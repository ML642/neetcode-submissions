class Solution {
public:
    int jump(vector<int>& nums) {   
        int x = 0;
        int answer = 0;

        int l = 0;
        int r = 0;
        
        while(r<nums.size()-1){
            
            int fatherest = 0;
            for(int i=l;i<=r;i++){        
                fatherest = max(fatherest,i+nums[i]);
            }
            l = r+1;
            r = fatherest;

            answer++;
            
            
        }
        return answer;

    }
};
