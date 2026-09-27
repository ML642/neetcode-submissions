class Solution {
public:
    int sum(int n){
        int sum=0;
        while(n){
            int digit = n%10;
            sum+=digit*digit;
            n=n/10; 
       }
       return sum;
    }
    bool isHappy(int n) {
        int slow,fast;
        slow = sum(n);
        fast = sum(sum(n));
        while(fast!=1 && fast!=slow){
            fast=sum(sum(fast));
            slow=sum(slow);
        }
        return fast==1;
    
    }
};
