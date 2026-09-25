class Solution {
public:
    vector<string> letters = {
    "", "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
};
    vector<string> answer;

    void dfs(string digits,int index, string& current){
        if(index == digits.size()){
            answer.push_back(current);
            return;
        }
        string letters_ = letters[digits[index]-'0'];  
        for(char c : letters_){
            current.push_back(c);
            dfs(digits,index+1,current);
            current.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        string current;
        if(digits.size()==0)return {};
        dfs(digits,0,current);
        return answer;
    }
};

