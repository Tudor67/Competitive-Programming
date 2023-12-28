class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        const int N = positions.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return (positions[lhs] < positions[rhs]);
             });
        
        stack<int> st;
        vector<int> h = healths;
        for(int i: p){
            if(directions[i] == 'R'){
                st.push(i);
            }else{
                while(!st.empty() && h[st.top()] < h[i]){
                    h[st.top()] = 0;
                    h[i] -= 1;
                    st.pop();
                }
                if(!st.empty() && h[st.top()] == h[i]){
                    h[st.top()] = 0;
                    h[i] = 0;
                    st.pop();
                }else if(!st.empty() && h[st.top()] > h[i] && h[i] >= 1){
                    h[st.top()] -= 1;
                    h[i] = 0;
                }
            }
        }
        
        vector<int> res;
        for(int i = 0; i < N; ++i){
            if(h[i] >= 1){
                res.push_back(h[i]);
            }
        }
        
        return res;
    }
};