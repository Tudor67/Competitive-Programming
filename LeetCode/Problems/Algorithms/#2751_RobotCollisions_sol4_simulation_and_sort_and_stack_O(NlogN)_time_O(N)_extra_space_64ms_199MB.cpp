class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        const int N = positions.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&positions](int lhs, int rhs){
                return (positions[lhs] < positions[rhs]);
             });

        vector<int> currHealths = healths;
        stack<int> st;

        for(int i: p){
            if(directions[i] == 'R'){
                st.push(i);
            }else{
                while(!st.empty()){
                    if(currHealths[st.top()] > currHealths[i]){
                        currHealths[st.top()] -= 1;
                        currHealths[i] = 0;
                        break;
                    }else if(currHealths[st.top()] < currHealths[i]){
                        currHealths[st.top()] = 0;
                        currHealths[i] -= 1;
                        st.pop();
                    }else{
                        currHealths[st.top()] = 0;
                        currHealths[i] = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }

        vector<int> res;
        for(int i = 0; i < N; ++i){
            if(currHealths[i] > 0){
                res.push_back(currHealths[i]);
            }
        }

        return res;
    }
};