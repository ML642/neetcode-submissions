class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int length = digits.size()-1;
       int last_digit = digits[length];

       digits[length]++;     

       for(int i=length;i>0;i--)
       {
           if(digits[i]==10){
            digits[i-1]++;
            digits[i]=0;
           }
       } 
       if(digits[0]==10){
        digits[0]=0;
        digits.insert(digits.begin(),1);
        
       }
       return digits;
    }
};
