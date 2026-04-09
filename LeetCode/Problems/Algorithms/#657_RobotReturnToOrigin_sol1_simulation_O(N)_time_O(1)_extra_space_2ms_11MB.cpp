class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, int> countOf;
        for(char c: moves){
            countOf[c] += 1;
        }
        return (countOf['L'] == countOf['R'] &&
                countOf['D'] == countOf['U']);
    }
};