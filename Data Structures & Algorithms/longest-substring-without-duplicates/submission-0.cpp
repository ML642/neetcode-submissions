class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int length = 0;

        int right = 0;
        int left = 0;

        while(right<s.size()){
            if(window.contains(s[right])){
                while(window.contains(s[right])){
                    window.erase(s[left]);
                    left++;
                }
                window.insert(s[right]);
                length = max(length,right-left+1);
                right++;
            }
            else{
                window.insert(s[right]);
                length = max(length,right-left+1);
                right++;
            }
        }
        return length;
    }
};
