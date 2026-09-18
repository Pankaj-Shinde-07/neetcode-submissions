class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto cur : tokens) {
            // number
            if (cur != "+" && cur != "-" && cur != "*" && cur != "/") {
                st.push(stoi(cur));
            }

            // operator
            else {
                int a = st.top();  // right
                st.pop();

                int b = st.top();  // left
                st.pop();

                if (cur == "+") st.push(b + a);
                if (cur == "-") st.push(b - a);
                if (cur == "*") st.push(b * a);
                if (cur == "/") st.push(b / a);
            }
        }

        return st.top();
    }
};