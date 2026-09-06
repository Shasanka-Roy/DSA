class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;

        int num = 0;
        string current = "";

        for (char c : s) {

            // Build the number
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // Start of a new encoded string
            else if (c == '[') {
                numStack.push(num);
                strStack.push(current);

                num = 0;
                current = "";
            }

            // End of encoded string
            else if (c == ']') {
                int repeat = numStack.top();
                numStack.pop();

                string previous = strStack.top();
                strStack.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += current;
                }

                current = previous + temp;
            }

            // Normal character
            else {
                current += c;
            }
        }

        return current;
    }
};
