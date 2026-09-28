class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> max_freq;
        queue<vector<int>> timer;

        vector<int> sizeq(26,0);
        for(int i=0;i<tasks.size();i++){
            int index = tasks[i] - 'A';
            sizeq[index]++;
        }

        for (int i = 0; i < 26; i++) {
          if (sizeq[i] > 0)
            max_freq.push(sizeq[i]);
            }
        
        int timer1 = 0;

        while(!max_freq.empty() || !timer.empty()){
             if (!timer.empty() && timer.front()[1] <= timer1) {
                max_freq.push(timer.front()[0]);
                timer.pop();
            }

            if (!max_freq.empty()) {
                int top = max_freq.top();
                max_freq.pop();

                top--;

                if (top > 0) {
                    timer.push({top, timer1 + n + 1});
                }
            }
            timer1++;
        }
        return timer1;

    }
};
