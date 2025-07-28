class Solution {
private:
    int computeGain(const string& S, char a, char b, int x, int y){
        int gain = 0;

        int aCount = 0;
        int bCount = 0;
        for(char ch: S){
            if(ch == a){
                aCount += 1;
            }else if(ch == b){
                if(aCount >= 1){
                    aCount -= 1;
                    gain += x;
                }else{
                    bCount += 1;
                }
            }else{
                gain += min(aCount, bCount) * y;
                aCount = 0;
                bCount = 0;
            }
        }

        return gain + min(aCount, bCount) * y;
    }

public:
    int maximumGain(string s, int x, int y) {
        return max(computeGain(s, 'a', 'b', x, y),
                   computeGain(s, 'b', 'a', y, x));
    }
};