class MinStack {
private:
    std::list<int> _mins;
    std::list<int> _stack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min_entry = _mins.empty() ? val : std::min(_mins.back(), val);

        _mins.push_back(min_entry);
        _stack.push_back(val);
    }
    
    void pop() {
        _stack.pop_back();
        _mins.pop_back();
    }
    
    int top() {
        return (_stack.back());
    }
    
    int getMin() {
        return (_mins.back());
    }
};
