class Solution {
public:
    vector<string> letters = {
    "", "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
    };
    vector<string> answers;

    void dfs(string& digits,int current,string& ans){
        if(current==digits.size()){
            answers.push_back(ans);
            return;
        }

        string letters_ = letters[digits[current] - '0'];

        for(auto letter : letters_ ){
            ans.push_back(letter);
            dfs(digits,current+1,ans);
            ans.pop_back();
        }        

    };



    vector<string> letterCombinations(string digits) {
       string s;
       if(digits.size()==0)return {};
       dfs(digits,0,s);
       return this->answers;
    }
};

