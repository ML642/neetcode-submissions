class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;

        while(right>left){
            int mid = (left+right)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        if(nums[left]==target)return left;
        else {
            return -1;
        }
    }
};
