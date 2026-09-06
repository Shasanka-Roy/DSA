class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {

            // Number
            if (token != "+" && token != "-" &&
                token != "*" && token != "/") {

                st.push(stoi(token));
            }
            else {
                // Get the last two numbers
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result;

                if (token == "+") {
                    result = a + b;
                }
                else if (token == "-") {
                    result = a - b;
                }
                else if (token == "*") {
                    result = a * b;
                }
                else {
                    result = a / b;
                }

                st.push(result);
            }
        }

        return st.top();
    }
};
