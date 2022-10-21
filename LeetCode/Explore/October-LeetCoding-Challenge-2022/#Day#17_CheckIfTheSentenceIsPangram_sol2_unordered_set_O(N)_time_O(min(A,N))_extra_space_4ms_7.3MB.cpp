class Solution {
public:
    bool checkIfPangram(string sentence) {
        const int A = 26;
        unordered_set<char> visSet(sentence.begin(), sentence.end());
        return ((int)visSet.size() == A);
    }
};