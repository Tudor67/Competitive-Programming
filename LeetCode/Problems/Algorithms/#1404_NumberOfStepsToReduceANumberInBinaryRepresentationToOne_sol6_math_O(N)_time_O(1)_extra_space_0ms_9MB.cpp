class Solution {
public:
    int numSteps(string s) {
        const int N = s.length();
        size_t lastIndexOfOne = s.find_last_of('1');
        if(lastIndexOfOne == 0){
            return N - 1;
        }
        return N - 1 + count(s.begin(), s.begin() + lastIndexOfOne, '0') + 2;
    }
};