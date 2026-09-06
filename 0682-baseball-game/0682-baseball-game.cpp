class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;

        for (string op : operations) {

            if (op == "C") {
                // Remove the last score
                scores.pop_back();
            }
            else if (op == "D") {
                // Double the last score
                scores.push_back(2 * scores.back());
            }
            else if (op == "+") {
                // Sum of the last two scores
                int n = scores.size();
                scores.push_back(scores[n - 1] + scores[n - 2]);
            }
            else {
                // Convert string to integer
                scores.push_back(stoi(op));
            }
        }

        // Calculate total
        int total = 0;

        for (int score : scores) {
            total += score;
        }

        return total;
    }
};
