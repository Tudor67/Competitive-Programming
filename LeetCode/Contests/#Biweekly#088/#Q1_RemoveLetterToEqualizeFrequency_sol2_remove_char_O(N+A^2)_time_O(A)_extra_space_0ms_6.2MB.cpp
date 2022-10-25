class Solution {
public:
    bool equalFrequency(string word) {
        const int N = word.length();
        const int A = 26;
        
        vector<int> count('z' + 1);
        for(char c: word){
            count[c] += 1;
        }
        
        for(char removedChar = 'a'; removedChar <= 'z'; ++removedChar){
            if(count[removedChar] >= 1){
                count[removedChar] -= 1;

                bool isValid = true;
                int targetCount = *max_element(count.begin() + 'a', count.end());
                for(char c = 'a'; c <= 'z'; ++c){
                    if(count[c] >= 1 && count[c] != targetCount){
                        isValid = false;
                    }
                }

                count[removedChar] += 1;

                if(isValid){
                    return true;
                }
            }
        }
        
        return false;
    }
};