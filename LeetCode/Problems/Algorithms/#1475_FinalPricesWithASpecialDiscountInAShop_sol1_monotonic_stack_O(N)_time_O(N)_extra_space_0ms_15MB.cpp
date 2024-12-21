class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int N = prices.size();

        vector<int> nextSmallerOrEqual(N, -1);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            while(!st.empty() && prices[st.top()] >= prices[i]){
                nextSmallerOrEqual[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            int j = nextSmallerOrEqual[i];
            if(i < j){
                res[i] = prices[i] - prices[j];
            }else{
                res[i] = prices[i];
            }
        }

        return res;
    }
};