class Solution {
private:
    int stoi(const string& S, int pos){
        int num = 0;
        while(pos < S.length() && isdigit(S[pos])){
            num = 10 * num + (S[pos] - '0');
            pos += 1;
        }
        return num;
    }
    
    string nextAtom(const string& S, int pos){
        string atom;
        atom += S[pos];
        pos += 1;
        while(pos < S.length() && islower(S[pos])){
            atom += S[pos];
            pos += 1;
        }
        return atom;
    }
    
    void ignoreAtom(const string& S, int& pos){
        pos += 1;
        while(pos < S.length() && islower(S[pos])){
            pos += 1;
        }
    }
    
    void ignoreIndex(const string& S, int& pos){
        while(pos < S.length() && isdigit(S[pos])){
            pos += 1;
        }
    }
    
public:
    string countOfAtoms(string formula) {
        const int N = formula.length();
        
        // compute multiplication factor for each opened and closed parenthesis
        vector<int> multiplicationFactor(N + 1, 1);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(formula[i] == '('){
                st.push(i);
            }else if(formula[i] == ')'){
                multiplicationFactor[i] = max(1, stoi(formula, i + 1));
                multiplicationFactor[st.top()] = multiplicationFactor[i];
                st.pop();
            }
        }
        
        // moving from left to right:
        // - compute current multiplication factor mF
        // - update count of each atom
        string atom;
        int cnt;
        int mF = 1;
        map<string, int> atomCnt;
        
        int i = 0;
        while(i < N){
            if(formula[i] == '('){
                mF *= multiplicationFactor[i];
                i += 1;
            }else if(formula[i] == ')'){
                mF /= multiplicationFactor[i];
                i += 1;
            }else if(isupper(formula[i])){
                atom = nextAtom(formula, i);
                ignoreAtom(formula, i);
                cnt = mF * max(1, stoi(formula, i));
                ignoreIndex(formula, i);
                atomCnt[atom] += cnt;
            }else{
                i += 1;
            }
        }
        
        // map<string, int> -> string
        string answer;
        for(const pair<string, int>& P: atomCnt){
            atom = P.first;
            cnt = P.second;
            answer += atom;
            if(cnt > 1){
                answer += to_string(cnt);
            }
        }
        
        return answer;
    }
};