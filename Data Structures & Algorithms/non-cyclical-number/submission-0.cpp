class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n!=1){

            int copy = n;
            int new_number=0;

            while(copy){
                int digit = copy%10;
                digit = digit*digit;
                new_number+=digit;
                copy=copy/10;
            }

            if(seen.contains(new_number)){
                return false;
            }
            else{
                seen.insert(new_number);
            }
            std::cout<<new_number<<endl;
            n = new_number;
        }
        return true;
    }
};
