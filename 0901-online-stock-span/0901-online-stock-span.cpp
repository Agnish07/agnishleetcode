class StockSpanner {
public:
    // Stack holds pairs of (price, span)
    stack<pair<int, int>> st;

    StockSpanner() {
        // Empty constructor — stack starts empty
    }

    int next(int price) {
        int span = 1;

        // While stack not empty and top price <= current price,
        // pop and accumulate the span
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current price and its span onto stack
        st.push({price, span});

        return span;
    }
};
