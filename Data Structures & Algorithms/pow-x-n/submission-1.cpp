class Solution {
public:
    double myPow(double x, int n) {
        double x_square = x;
        bool c=false;
        double ost=1;
        int power;
        if(n==0){
            return 1;
        }
        if(n<0){
            n = -n;
            c = true;
        }
        while(n>1){
            if(n%2==0){
                power++;
                x_square = x_square*x_square;
            }
            else{
                ost *= x_square;
                x_square = x_square*x_square;
            }
            n=n/2;
        }
        if(c){
            return 1/(x_square*ost);
        }
        else{
            return x_square * ost;
            }
    }
};
