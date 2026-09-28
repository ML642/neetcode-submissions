class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> q;
    int k; 
    KthLargest(int k, vector<int>& nums) {
        this->q = priority_queue<int,vector<int>,greater<int>> ();
        this->k = k;
        for(int i=0;i<nums.size();i++){
            if(q.size()<k){
                q.push(nums[i]);
            }
            else{
                if(q.top()<nums[i]){
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(q.size()<k){
                q.push(val);
            }
            else{
                if(q.top()<val){
                    q.pop();
                    q.push(val);
                }
            }
        return q.top();
    }
};
