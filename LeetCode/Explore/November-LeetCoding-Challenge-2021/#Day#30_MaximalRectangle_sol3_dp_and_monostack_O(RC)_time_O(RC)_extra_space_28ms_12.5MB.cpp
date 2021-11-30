class Solution {
private:
    int computeMaxArea(vector<int>& h){
        const int N = h.size();
        
        int maxArea = 0;
        
        stack<int> st;
        for(int i = 0; i < N; ++i){
            int lastIdx = -1;
            while(!st.empty() && h[st.top()] > h[i]){
                int area = (i - st.top()) * h[st.top()];
                lastIdx = st.top();
                maxArea = max(maxArea, area);
                st.pop();
            }
            if(lastIdx >= 0){
                if(h[i] >= 1){
                    h[lastIdx] = h[i];
                    st.push(lastIdx);
                }
            }else if(h[i] >= 1){
                st.push(i);
            }
        }
        
        while(!st.empty()){
            int area = (N - st.top()) * h[st.top()];
            maxArea = max(maxArea, area);
            st.pop();
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