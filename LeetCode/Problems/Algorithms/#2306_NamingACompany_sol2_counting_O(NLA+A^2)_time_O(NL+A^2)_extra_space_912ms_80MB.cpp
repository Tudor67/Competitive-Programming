class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        const int N = ideas.size();
        const int A = 26;

        // count[c1 - 'a'][c2 - 'a']: number of strings that allow first char to be swapped from c1 to c2
        vector<vector<long long>> count(A, vector<long long>(A));
        unordered_set<string> ideasSet(ideas.begin(), ideas.end());
        for(int i = 0; i < N; ++i){
            char originalFirstChar = ideas[i][0];
            string newIdea = ideas[i];
            for(char c = 'a'; c <= 'z'; ++c){
                newIdea[0] = c;
                if(!ideasSet.count(newIdea)){
                    count[originalFirstChar - 'a'][c - 'a'] += 1;
                }
                newIdea[0] = originalFirstChar;
            }
        }

        long long res = 0;
        for(char c1 = 'a'; c1 <= 'z'; ++c1){
            for(char c2 = 'a'; c2 <= 'z'; ++c2){
                res += count[c1 - 'a'][c2 - 'a'] * count[c2 - 'a'][c1 - 'a'];
            }
        }

        return res;
    }
};