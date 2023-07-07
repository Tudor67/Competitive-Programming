class Solution {
private:
    bool containsDuplicates(string& s){
        int charMask = 0;
        for(char c: s){
            int bit = c - 'a';
            if((charMask >> bit) & 1){
                return true;
            }
            charMask |= (1 << bit);
        }
        return false;
    }

public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }

        const int N = s.length();
        vector<int> badIndices;
        for(int i = 0; i < N && (int)badIndices.size() < 3; ++i){
            if(s[i] != goal[i]){
                badIndices.push_back(i);
            }
        }

        if((int)badIndices.size() == 0 && containsDuplicates(s)){
            return true;
        }

        if((int)badIndices.size() == 2 &&
           s[badIndices[0]] == goal[badIndices[1]] &&
           s[badIndices[1]] == goal[badIndices[0]]){
            return true;
        }

        return false;
    }
};