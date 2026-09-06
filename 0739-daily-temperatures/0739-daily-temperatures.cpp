class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);

        stack<int> st;  // stores indices

        for (int i = 0; i < n; i++) {

            // Current temperature is warmer
            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {

                int previousDay = st.top();
                st.pop();

                answer[previousDay] = i - previousDay;
            }

            // Current day waits for a warmer day
            st.push(i);
        }

        return answer;
    }
};
