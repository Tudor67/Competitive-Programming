class Solution {
private:
    bool contains(const string& S, const string& P){
        const int N = S.length();
        const int M = P.length();
        
        const string PS = P + "$" + S;
        const int L = PS.length();
        
        static vector<int> p;
        p.assign(L, 0);
        for(int i = 1; i < L; ++i){
            int k = p[i - 1];
            while(k > 0 && PS[k] != PS[i]){
                k = p[k - 1];
            }
            if(PS[k] == PS[i]){
                p[i] = k + 1;
            }
            if(p[i] == M){
                return true;
            }
        }
        
        return false;
    }
    
public:
    vector<string> stringMatching(vector<string>& words) {
        const int N = words.size();
        vector<string> answer;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(words[j].length() > words[i].length() && contains(words[j], words[i])){
                    answer.push_back(words[i]);
                    break;
                }
            }
        }
        return answer;
    }
};