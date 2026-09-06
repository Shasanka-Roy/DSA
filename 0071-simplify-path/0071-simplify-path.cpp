class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;

        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {

            // Ignore empty parts and "."
            if (part == "" || part == ".") {
                continue;
            }

            // Go to parent directory
            if (part == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                // Normal directory
                st.push(part);
            }
        }

        // Build the result
        string result = "";

        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};
