class Solution {
public:
    string frequencySort(string s) {
        const int N = s.length();
        const int A = 125;
        
        vector<int> freqOf(A);
        for(char c: s){
            freqOf[c] += 1;
        }
        
        vector<pair<int, char>> freqChar;
        for(char c = 0; c < A; ++c){
            if(freqOf[c] >= 1){
                freqChar.push_back({freqOf[c], c});
            }
        }
        
        sort(freqChar.rbegin(), freqChar.rend());
        
        string res;
        for(const pair<int, char>& P: freqChar){
            char c = P.second;
            res.append(freqOf[c], c);
        }
        
        return res;
    }
};