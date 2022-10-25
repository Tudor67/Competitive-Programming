class Solution {
public:
    bool equalFrequency(string word) {
        const int N = word.length();
        const int A = 26;
        
        unordered_map<char, int> count;
        for(int removedIndex = 0; removedIndex < N; ++removedIndex){
            count.clear();
            for(int i = 0; i < N; ++i){
                if(i != removedIndex){
                    count[word[i]] += 1;
                }
            }
            
            bool isValid = true;
            int targetCount = count.begin()->second;
            for(const pair<char, int>& P: count){
                int currentCount = P.second;
                if(currentCount != targetCount){
                    isValid = false;
                }
            }
            
            if(isValid){
                return true;
            }
        }
        
        return false;
    }
};