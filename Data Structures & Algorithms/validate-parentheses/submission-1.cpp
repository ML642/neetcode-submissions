class Solution {
public:
    bool isValid(string s) {
        stack<char> stac;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stac.push(s[i]);
            }

            if(s[i]==')'){
                if(stac.empty() || stac.top()!='('){
                    return false;
                }
                else{
                    stac.pop();
                }
            }
            if(s[i]==']'){
                if(stac.empty() || stac.top()!='['){
                    
                        return false;
                }
                
                        stac.pop();
        
                }
            
           if(s[i]=='}'){
                if(stac.empty() || stac.top()!='{'){
                    
                        return false;
                }
                
                        stac.pop();
        
                }
            }
            return stac.empty();
        }
        
    };

