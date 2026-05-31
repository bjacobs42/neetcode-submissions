class MinStack {
private:
    std::list<int> _mins;
    std::list<int> _stack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (_mins.empty())
            _mins.push_back(val);
        else if (val <= _mins.back())
            _mins.push_back(val);
        _stack.push_back(val);
    }
    
    void pop() {
        if (top() == getMin())
            _mins.pop_back();
        _stack.pop_back();
    }
    
    int top() {
        return (_stack.back());
    }
    
    int getMin() {
        return (_mins.back());
    }
};
