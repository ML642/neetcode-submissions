class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int answer=0;

        int left=0;
        int right=0;
        while(right<s.size()){
            while(window.contains(s[right])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            answer=max(answer,right-left+1);
            right++;
        }
        return answer;
    }
};
