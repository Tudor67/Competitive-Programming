class Solution {
private:
    int computeMaxArea(vector<int>& h){
        const int N = h.size();
        
        stack<int> st;
        vector<int> nextSmaller(N, N);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && h[st.top()] > h[i]){
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
            while(!st.empty() && h[i] < h[st.top()]){
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        int maxArea = 0;
        for(int i = 0; i < N; ++i){
            int area = h[i] * (nextSmaller[i] - prevSmaller[i] - 1);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<vector<int>> vSum(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(matrix[row][col] == '1'){
                    vSum[row][col] = 1;
                    if(row >= 1){
                        vSum[row][col] += vSum[row - 1][col];
                    }
                }
            }
        }
        
        int maxArea = 0;
        for(int row = 0; row < ROWS; ++row){
            maxArea = max(maxArea, computeMaxArea(vSum[row]));
        }
        
        return maxArea;
    }
};