class Solution {
private:
    int applyOperation(string& s, char a, char b, int opPoints){
        const int N = s.length();

        int totalPoints = 0;
        int i = -1;
        for(int j = 0; j < N; ++j){
            if(i >= 0 && s[i] == a && s[j] == b){
                totalPoints += opPoints;
                i -= 1;
            }else{
                i += 1;
                s[i] = s[j];
            }
        }

        s.resize(i + 1);

        return totalPoints;
    }

public:
    int maximumGain(string s, int x, int y) {
        int maxPoints = 0;
        if(x < y){
            maxPoints += applyOperation(s, 'b', 'a', y);
            maxPoints += applyOperation(s, 'a', 'b', x);
        }else{
            maxPoints += applyOperation(s, 'a', 'b', x);
            maxPoints += applyOperation(s, 'b', 'a', y);
        }
        return maxPoints;
    }
};