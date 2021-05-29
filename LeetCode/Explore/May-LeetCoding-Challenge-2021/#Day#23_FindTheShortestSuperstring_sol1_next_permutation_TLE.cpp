class Solution {
private:
    string minNonOverlappingString(const string& S1, const string& S2){
        int bestPosition = 0;
        for(int i = (int)S1.length() - 1, j = 0; i >= 0 && j < (int)S2.length(); --i, ++j){
            bool isValid = true;
            for(int k = 0; isValid && k <= j; ++k){
                if(S1[i + k] != S2[k]){
                    isValid = false;
                }
            }
            if(isValid){
                bestPosition = j + 1;
            }
        }
        return S2.substr(bestPosition);
    }
    
public:
    string shortestSuperstring(vector<string>& words) {
        const int N = words.size();
        
        string answer;
        if(N == 1){
            answer = words[0];
        }else{
            vector<int> p(N);
            iota(p.begin(), p.end(), 0);
            do{
                string candidate;
                for(int i = 0; i < N; ++i){
                    candidate += minNonOverlappingString(candidate, words[p[i]]);
                }
                
                if(answer.empty() || candidate.length() < answer.length()){
                    answer = candidate;
                }
            }while(next_permutation(p.begin(), p.end()));
        }
        
        return answer;
    }
};