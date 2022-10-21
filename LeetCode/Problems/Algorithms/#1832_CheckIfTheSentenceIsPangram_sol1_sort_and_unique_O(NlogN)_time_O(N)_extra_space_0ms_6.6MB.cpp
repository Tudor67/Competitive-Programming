class Solution {
public:
    bool checkIfPangram(string sentence) {
        const int N = sentence.size();
        const int A = 26;
        
        string s = sentence;
        sort(s.begin(), s.end());
        s.resize(unique(s.begin(), s.end()) - s.begin());
        
        return ((int)s.size() == A);
    }
};