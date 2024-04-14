class Solution {
private:
    int computeMaxArea(const vector<int>& H){
        const int N = H.size();

        vector<int> nextSmaller(N, N);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            while(!st.empty() && H[st.top()] > H[i]){
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        vector<int> prevSmaller(N, -1);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && H[i] < H[st.top()]){
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < N; ++i){
            int area = (nextSmaller[i] - prevSmaller[i] - 1) * H[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int maxArea = 0;
        vector<int> colSum(COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(matrix[row][col] == '0'){
                    colSum[col] = 0;
                }else{
                    colSum[col] += (matrix[row][col] - '0');
                }
            }
            maxArea = max(maxArea, computeMaxArea(colSum));
        }

        return maxArea;
    }
};