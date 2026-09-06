class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int asteroid : asteroids) {
            bool destroyed = false;

            // Collision happens when:
            // previous asteroid is moving right
            // current asteroid is moving left
            while (!st.empty() && st.back() > 0 && asteroid < 0) {

                if (st.back() < -asteroid) {
                    // Previous asteroid is smaller
                    st.pop_back();
                    continue;
                }
                else if (st.back() == -asteroid) {
                    // Both explode
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else {
                    // Current asteroid is smaller
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(asteroid);
            }
        }

        return st;
    }
};
