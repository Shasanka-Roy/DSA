class StockSpanner {
private:
    // pair = {price, span}
    stack<pair<int, int>> st;

public:
    StockSpanner() {
    }

    int next(int price) {
        int span = 1;

        // Combine previous spans while their price <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};
