class Solution {
private:
    int largest_rectangle_area(vector<int>& heights) {
        const int N = heights.size();
        int answer = 0;
        int zero_pos = -1;
        stack<int> st;
        
        for(int i = 0; i <= N; ++i){
            // h: current height
            // left_pos: position of h after removing from stack all H > h
            //           keep the leftmost position 
            int h = (i == N ? 0 : heights[i]);
            int left_pos = i;
            
            // remove from stack and update answer
            while(!st.empty() && heights[st.top()] >= h){
                answer = max((i - st.top()) * heights[st.top()], answer);
                left_pos = st.top();
                st.pop();
            }
            
            // update answer
            if(st.empty()){
                answer = max((i - zero_pos) * h, answer);
            }else{
                answer = max((i - left_pos + 1) * h, answer);
            }
            
            // insert into stack and update heights
            if(st.empty()){
                if(zero_pos + 1 < N){
                    st.push(zero_pos + 1);
                    heights[zero_pos + 1] = h;
                }
            }else{
                st.push(left_pos);
                heights[left_pos] = h;
            }
            
            // update position of last zero
            if(h == 0){
                zero_pos = i;
            }
        }
        
        return answer;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int answer = 0;
        
        if(!matrix.empty()){
            const int N = matrix.size();
            const int M = matrix[0].size();
            vector<vector<int>> heights(N, vector<int>(M, 0));

            for(int j = 0; j < M; ++j){
                heights[0][j] = matrix[0][j] - '0';
            }

            for(int i = 1; i < N; ++i){
                for(int j = 0; j < M; ++j){
                    if(matrix[i][j] == '1'){
                        heights[i][j] = 1 + heights[i - 1][j];
                    }
                }
            }

            for(int i = 0; i < N; ++i){
                answer = max(largest_rectangle_area(heights[i]), answer);
            }
        }
        
        return answer;
    }
};