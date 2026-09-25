class Solution {
public:
    unordered_map <char,int> freq;

    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        unordered_set<char> window;
        int max_length = 0;
        int answer = 0;
        while(right<s.size()){
            freq[s[right]]++;
            max_length = max(max_length,freq[s[right]]);

            if(right-left+1-max_length>k){
                freq[s[left]]--;
                left++;
            }
            
            
            
            answer = max(answer,right-left+1);
            right++;
            
        }
        return answer;
    }
};
