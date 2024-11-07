class Solution {
public:
    bool rotateString(string s, string goal) {
        return (s.length() == goal.length() &&
                (goal + goal).find(s) != string::npos);
    }
};