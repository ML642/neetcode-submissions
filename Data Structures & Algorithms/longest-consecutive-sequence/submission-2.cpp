class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> a;
        for(int i=0;i<nums.size();i++){
            a[nums[i]]++;
        }
        int answer=0;
        for(auto& [key,value] : a){
            if(a.contains(key-1)){
                continue;
            }
            int count = 1;
            int copy = key;
            while( a.contains(copy+1) && a[copy+1]!=0){
                a[copy+1]=0;
                count++;
                copy++;
            }
            answer = max(answer,count);
        }
        return answer;
    }
};
