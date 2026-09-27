class Solution {
public:
    int trap(vector<int>& height) {
        int open = 0;
        int weight = 0;
        int closed = 0;

        int answer=0;
        for(int i=0;i<height.size();i++){
            if(height[i]>=weight){
                answer += weight * (i-open-1)-closed;
                weight = height[i];
                open = i;
                closed=0;
                std::cout<<answer<<'f';
            }
            else if(weight!=0 && height[i]<weight){
                closed+=height[i];
            }
        }
        weight=0;
        closed=0;
        std::cout<<open;
        int left = open;
        for(int i=height.size()-1;i>=left;i--){
            if(height[i]>=weight){
                answer += weight * (open-i-1)-closed;
                weight = height[i];
                open = i;
                closed=0;
                std::cout<<answer<<'saasss'<<endl;
            }
            else if(weight!=0 && height[i]<weight){
                closed+=height[i];
            }
        }

        return answer;
    }
};
