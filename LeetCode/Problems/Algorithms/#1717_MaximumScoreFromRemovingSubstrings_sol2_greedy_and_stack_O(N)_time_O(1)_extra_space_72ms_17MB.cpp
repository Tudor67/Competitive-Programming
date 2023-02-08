class Solution {
private:
    void remove(string& s, char a, char b, int operationGain, int& totalGain){
        int i = -1;
        for(char c: s){
            if(i >= 0 && s[i] == a && c == b){
                i -= 1;
                totalGain += operationGain;
            }else{
                i += 1;
                s[i] = c;
            }
        }
        s.resize(i + 1);
    }

public:
    int maximumGain(string s, int x, int y) {
        int maxGain = 0;
        if(x >= y){
            remove(s, 'a', 'b', x, maxGain);
            remove(s, 'b', 'a', y, maxGain);
        }else{
            remove(s, 'b', 'a', y, maxGain);
            remove(s, 'a', 'b', x, maxGain);
        }
        return maxGain;
    }
};