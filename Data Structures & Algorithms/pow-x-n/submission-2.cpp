class Solution {
public:
    double myPow(double x, int n) {
        double x_square = x;
        bool c=false;
        double ost=1;
        if(n==0){
            return 1;
        }
        if(n<0){
            n = -n;
            c = true;
        }
        double answer=1;
        while(n>0){
            if(n%2==1){
                answer*=x;
            }
            x=x*x;
            n=n/2;
        }
        if(c){
            return 1/answer;
        }
        else{
            return answer;
            }
    }
};
