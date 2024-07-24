class Solution {
private:
    int getCoefStartingAt(string& formula, int i){
        const int N = formula.length();
        int coef = 0;
        while(i < N && isdigit(formula[i])){
            coef = coef * 10 + (formula[i] - '0');
            i += 1;
        }
        return max(coef, 1);
    }

public:
    string countOfAtoms(string formula) {
        const int N = formula.length();

        vector<int> multCoef(N, 1);
        vector<int> divCoef(N, 1);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(formula[i] == '('){
                st.push(i);
            }else if(formula[i] == ')'){
                int coef = getCoefStartingAt(formula, i + 1);
                multCoef[st.top()] = coef;
                divCoef[i] = coef;
                st.pop();
            }
        }

        map<string, int> freq;
        int coef = 1;
        for(int i = 0; i < N; ++i){
            coef *= multCoef[i];
            coef /= divCoef[i];
            if(isupper(formula[i])){
                int j = i + 1;
                while(j < N && islower(formula[j])){
                    j += 1;
                }
                string elem = formula.substr(i, j - i);
                freq[elem] += coef * getCoefStartingAt(formula, j);
            }
        }

        string res;
        for(const pair<const string, int>& P: freq){
            string elem = P.first;
            int elemFreq = P.second;
            res += elem;
            if(elemFreq >= 2){
                res += to_string(elemFreq);
            }
        }

        return res;
    }
};