class Solution {
private:
    int wordToMask(const string& WORD){
        int mask = 0;
        for(char c: WORD){
            mask |= (1 << (c - 'a'));
        }
        return mask;
    }
    
public:
    int maxProduct(vector<string>& words) {
        const int N = words.size();
        vector<int> masks(N);
        for(int i = 0; i < N; ++i){
            masks[i] = wordToMask(words[i]);
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if((masks[i] & masks[j]) == 0){
                    answer = max((int)words[i].length() * (int)words[j].length(), answer);
                }
            }
        }
        
        return answer;
    }
};