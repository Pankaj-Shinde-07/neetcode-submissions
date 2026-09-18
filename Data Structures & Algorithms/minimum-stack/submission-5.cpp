class MinStack {
    stack<int> s1, s2;

   public:
    MinStack() {}

    void push(int val) {
        s1.push(val);

        if (s2.empty() || s2.top() >= val) {
            s2.push(val);
        }
    }

    void pop() {
        if (!s2.empty()) {
            if (s1.top() == s2.top()) {
                s2.pop();
            }
        }
        if (!s1.empty()) {
            s1.pop();
        }
    }

    int top() {
        if (!s1.empty()) {
            return s1.top();
        }
    }

    int getMin() {
        if (!s2.empty()) {
            return s2.top();
        }
        return -1;
    }
};
