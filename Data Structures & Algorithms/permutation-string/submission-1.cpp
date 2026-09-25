class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> map_1;
        unordered_map<char,int> map_2;

        if(s1.size()>s2.size())return false;
        for(int i=0;i<s1.size();i++){
            map_1[s1[i]]++;
        }
        int right = 0;
        int left = 0;        

        while(right<s1.size()){
            map_2[s2[right]]++;
            right++;
        }
        while(right<s2.size()){
            if(map_1 == map_2){
                return true;
            }
            map_2[s2[right]]++;
            map_2[s2[left]]--;
            if(map_2[s2[left]]==0){
                map_2.erase(s2[left]);
            }
            right++;
            left++;
        }
        if(map_1==map_2)return true;
        return false;
    }
};
