class StockSpanner {
private:
    stack<pair<int, int>> st;
    int index;
    
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        index += 1;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int span = index;
        if(!st.empty()){
            span = index - st.top().second;
        }
        st.push({price, index});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */