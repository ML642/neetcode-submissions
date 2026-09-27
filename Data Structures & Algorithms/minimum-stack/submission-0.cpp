class MinStack {
public:
    stack<int> numbers;
    stack<int> minimum;
    MinStack() {
        this->numbers=stack<int>();
        this->minimum=stack<int>();        
    }
    
    void push(int val) {
        this->numbers.push(val);
        if(this->minimum.empty() || this->minimum.top() > val){
            this->minimum.push(val);
        }
        else{
            this->minimum.push(this->minimum.top());
        }
    }
    
    void pop() {
        this->minimum.pop();
        this->numbers.pop();
    }
    
    int top() {
        return this->numbers.top();
    }
    
    int getMin() {
        return this->minimum.top();
    }
};
