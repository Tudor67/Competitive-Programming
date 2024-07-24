class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        const int N = healths.size();

        vector<int> currentHealths = healths;

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (positions[lhs] < positions[rhs]);
             });

        stack<int> st;
        for(int i: p){
            if(directions[i] == 'R'){
                st.push(i);
            }else{
                while(!st.empty() && currentHealths[i] > 0){
                    if(currentHealths[st.top()] < currentHealths[i]){
                        currentHealths[i] -= 1;
                        currentHealths[st.top()] = 0;
                        st.pop();
                    }else if(currentHealths[st.top()] > currentHealths[i]){
                        currentHealths[i] = 0;
                        currentHealths[st.top()] -= 1;
                    }else{
                        currentHealths[i] = 0;
                        currentHealths[st.top()] = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<int> res;
        for(int i = 0; i < N; ++i){
            if(currentHealths[i] > 0){
                res.push_back(currentHealths[i]);
            }
        }

        return res;
    }
};