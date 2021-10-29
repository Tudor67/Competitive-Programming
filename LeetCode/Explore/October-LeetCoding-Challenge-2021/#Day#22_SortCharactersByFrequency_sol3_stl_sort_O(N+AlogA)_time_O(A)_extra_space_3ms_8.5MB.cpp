class Solution {
public:
    string frequencySort(string s) {
        const int N = s.length();
        const int A = 126;
        
        vector<int> charCount(A, 0);
        for(char c: s){
            charCount[c] += 1;
        }
        
        vector<pair<int, char>> fc;
        for(char c = 0; c < A; ++c){
            if(charCount[c] > 0){
                fc.push_back({charCount[c], c});
            }
        }
        
        sort(fc.rbegin(), fc.rend());
        
        string sortedS;
        for(const pair<int, char>& P: fc){
            int freq = P.first;
            char c = P.second;
            sortedS.append(freq, c);
        }
        
        return sortedS;
    }
};