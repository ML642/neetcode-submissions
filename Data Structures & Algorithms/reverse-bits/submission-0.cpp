class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i=0;
        int count = 31;
        while(n){
            int x = n&1;
            x = x<<count;
            std::cout<<x;
            i = i | x;
            n=n>>1;
            count--;
        }
        return i;
    }
};
