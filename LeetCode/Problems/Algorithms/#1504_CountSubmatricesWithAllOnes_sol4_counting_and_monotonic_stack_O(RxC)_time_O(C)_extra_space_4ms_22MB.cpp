class Solution {
private:
    void computeContrib(vector<int>& h, vector<int>& contrib){
        stack<int> st;
        
        for(int i = 0; i < (int)h.size(); ++i){
            while(!st.empty() && h[st.top()] > h[i]){
                st.pop();
            }
            
            if(st.empty()){
                contrib[i] = h[i] * (i + 1);
            }else{
                contrib[i] = h[i] * (i - st.top()) + contrib[st.top()];
            }

            st.push(i);
        }
    }

public:
    int numSubmat(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        int res = 0;
        vector<int> h(COLS);
        vector<int> contrib(COLS);

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(mat[row][col] == 0){
                    h[col] = 0;
                }else{
                    h[col] += 1;
                }
            }

            computeContrib(h, contrib);

            res += accumulate(contrib.begin(), contrib.end(), 0);
        }

        return res;
    }
};