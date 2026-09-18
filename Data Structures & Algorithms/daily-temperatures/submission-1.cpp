class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();

        stack<pair<int, int>> stk;  // num - ind

        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            
            // stack containe elements

            while (!stk.empty() && stk.top().first <= temp[i]) {
                stk.pop();
            }

            if (stk.empty()) {
                ans[i] = 0;
                stk.push({temp[i], i});
            }else{
                ans[i]=stk.top().second - i;
                stk.push({temp[i],i});
            }
        }

        return ans;
    }
};
