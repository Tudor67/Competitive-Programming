class Solution {
private:
    int stringToMask(const string& S){
        int mask = 0;
        for(char c: S){
            mask |= (1 << (c - 'a'));
        }
        return mask;
    }
    
public:
    int maxProduct(vector<string>& words) {
        const int N = words.size();
        
        vector<int> masks(N);
        for(int i = 0; i < N; ++i){
            masks[i] = stringToMask(words[i]);
        }
        
        int maxProd = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if((masks[i] & masks[j]) == 0){
                    int prod = words[i].length() * words[j].length();
                    maxProd = max(maxProd, prod);
                }
            }
        }
        
        return maxProd;
    }
};