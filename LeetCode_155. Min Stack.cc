class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {

        //压入数据进
        _st.push(val);

        //
        if(_minSt.empty() || val <= _minSt.top())
        {
            _minSt.push(val);
        }
    }
    
    void pop() {
        if(_st.top() == _minSt.top())
        {
            _minSt.pop();
        }

        _st.pop();
    }
    
    int top() {
        return _st.top();
    }
    
    int getMin() {
        return _minSt.top();
    }
private:
    stack<int> _st;
    stack<int>_minSt;
};