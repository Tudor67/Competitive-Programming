class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        const int N = s.length();

        vector<int> parIndices;
        int lettersMask = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '(' || s[i] == ')'){
                parIndices.push_back(i);
            }else{
                lettersMask |= (1 << i);
            }
        }

        const int P = parIndices.size();
        const int FULL_MASK = (1 << P) - 1;

        int minRemovals = P;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            int balance = 0;
            bool isValid = true;
            for(int bit = 0; bit < P; ++bit){
                if((mask >> bit) & 1){
                    int i = parIndices[bit];
                    if(s[i] == '('){
                        balance += 1;
                    }else if(balance > 0){
                        balance -= 1;
                    }else{
                        isValid = false;
                    }
                }
            }

            if(isValid && balance == 0){
                int currRemovals = P - popcount((unsigned int)mask);
                minRemovals = min(minRemovals, currRemovals);
            }
        }

        unordered_set<string> res;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            int balance = 0;
            bool isValid = true;
            int resMask = lettersMask;
            for(int bit = 0; bit < P; ++bit){
                if((mask >> bit) & 1){
                    int i = parIndices[bit];
                    resMask |= (1 << i);
                    if(s[i] == '('){
                        balance += 1;
                    }else if(balance > 0){
                        balance -= 1;
                    }else{
                        isValid = false;
                    }
                }
            }

            int currRemovals = P - popcount((unsigned int)mask);
            if(isValid && balance == 0 && currRemovals == minRemovals){
                string resStr;
                for(int bit = 0; bit < N; ++bit){
                    if((resMask >> bit) & 1){
                        resStr += s[bit];
                    }
                }
                res.insert(resStr);
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};