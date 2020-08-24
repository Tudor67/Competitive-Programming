class Solution {
private:
    int largest_rectangle_area(vector<int>& heights, const int& NUM_COLS) {
        int answer = 0;
        stack<int> st;
        st.push(0);
        
        for(int i = 1; i <= NUM_COLS + 1; ++i){
            int idx = st.top();
            while(heights[idx] > heights[i]){
                st.pop();
                answer = max((i - (st.top() + 1)) * heights[idx], answer);
                idx = st.top();
            }
            st.push(i);
        }
        
        return answer;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        
        const int N = matrix.size();
        const int M = matrix[0].size();
        vector<vector<int>> heights(N + 2, vector<int>(M + 2, 0));
        
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                if(matrix[i - 1][j - 1] == '1'){
                    heights[i][j] = 1 + heights[i - 1][j];
                }
            }
        }
        
        int answer = 0;
        for(int i = 1; i <= N; ++i){
            answer = max(largest_rectangle_area(heights[i], M), answer);
        }
        
        return answer;
    }
};