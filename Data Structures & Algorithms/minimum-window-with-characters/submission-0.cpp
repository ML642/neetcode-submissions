class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mapa1;
        unordered_map<char,int> mapa2;
        for(auto i:t){
            mapa1[i]++;
        }
        
        int satisfies=0;
        string retur;
        int answer=INT_MAX;
        int left=0;
        int right=0;

        int bestLeft=0;

        while(right<s.size()){
            
            if(mapa1.contains(s[right])){
                mapa2[s[right]]++;
                if(mapa1[s[right]] == mapa2[s[right]]){
                    satisfies++;
                }    
            }
            if(satisfies==mapa1.size()){
                if(answer>right-left+1){
                    answer=right-left+1;
                    bestLeft=left;
                }
            }
            
            while(satisfies == mapa1.size()){
                if(answer>right-left+1){
                    answer=right-left+1;
                    bestLeft=left;
                }

                char removed = s[left];

                if (mapa1.contains(removed)) {
                    mapa2[removed]--;

                    if (mapa2[removed] < mapa1[removed]) {
                        satisfies--;
                    }
                }
                left++;
            }
            right++;
        }
        if(answer==INT_MAX)return "";
        return s.substr(bestLeft,answer);
    }
};
