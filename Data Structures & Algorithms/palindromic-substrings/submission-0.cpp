class Solution {
public:
    int count(string s,int l,int r){
        int count=0;
        while(l>=0 && r<s.size() && s[r] == s[l]){
            count++;
            r++;
            l--;
        }
        return count;
    }

    int countSubstrings(string s) {
        int count1 = 0;
        for(int i=0;i<s.size();i++){
            count1 += count(s,i,i);
            count1 += count(s,i,i+1);
        }
        return count1;
    }
};
