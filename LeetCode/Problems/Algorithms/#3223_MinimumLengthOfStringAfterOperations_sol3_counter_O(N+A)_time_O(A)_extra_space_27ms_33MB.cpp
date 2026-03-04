class Solution {
public:
    int minimumLength(string s) {
        const int N = s.length();
        const int A = 26;
        const char FIRST_ELEM = 'a';

        vector<int> remFreqOf(A);
        for(char c: s){
            int cID = c - FIRST_ELEM;
            remFreqOf[cID] += 1;
            if(remFreqOf[cID] > 2){
                remFreqOf[cID] -= 2;
            }
        }

        return accumulate(remFreqOf.begin(), remFreqOf.end(), 0);
    }
};