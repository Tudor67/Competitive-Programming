class Solution {
private:
    static int getCanonicalForm(const string& WORD){
        int canonicalForm = 0;
        for(char c: WORD){
            canonicalForm |= (1 << (c - 'a'));
        }
        return canonicalForm;
    }
    
public:
    int maxProduct(vector<string>& words) {
        const int N = words.size();
        
        vector<int> canonicalForms(N);
        for(int i = 0; i < N; ++i){
            canonicalForms[i] = getCanonicalForm(words[i]);
        }
        
        int answer = 0;
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if((canonicalForms[i] & canonicalForms[j]) == 0){
                    answer = max((int)words[i].length() * (int)words[j].length(), answer);
                }
            }
        }
        
        return answer;
    }
};