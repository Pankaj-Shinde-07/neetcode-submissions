class Solution {
public:

    bool isOperator(string s){
        if(s=="+" || s=="-" ||s=="*" || s=="/"){
            return true;
        }

        return false;
    }

    int retVal(int a, int b, string oprtr){
        if(oprtr=="+"){
            return a+b;
        }else if(oprtr=="-"){
            return b-a;
        }else if(oprtr=="*"){
            return a*b;
        }else if(oprtr=="/"){
            return b/a;
        }

        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(string s : tokens){
            if(isOperator(s)){
                //operator
                int upper = stk.top();
                stk.pop();
                int lower = stk.top();
                stk.pop();

                int curr = retVal(upper,lower,s);
                stk.push(curr);
            }else{
                //digits
                stk.push(stoi(s));
            }
        }

        return stk.top();
        
    }
};
