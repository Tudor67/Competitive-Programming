class Solution {
private:
    int computeMaxPoints(const string& S, const int START_INDEX, const int END_INDEX, int x, int y){
        const int N = S.length();
        const int DIRECTION = (START_INDEX < END_INDEX ? 1 : -1);

        if(x < y){
            return computeMaxPoints(S, N - 1, -1, y, x);
        }

        int maxPoints = 0;
        int aCount = 0;
        int bCount = 0;
        for(int i = START_INDEX; i != END_INDEX; i += DIRECTION){
            if(S[i] == 'a'){
                aCount += 1;
            }else if(S[i] == 'b'){
                if(aCount >= 1){
                    maxPoints += x;
                    aCount -= 1;
                }else{
                    bCount += 1;
                }
            }else{
                maxPoints += min(aCount, bCount) * y;
                aCount = 0;
                bCount = 0;
            }
        }

        return maxPoints + min(aCount, bCount) * y;
    }

public:
    int maximumGain(string s, int x, int y) {
        const int N = s.length();
        return computeMaxPoints(s, 0, N, x, y);
    }
};