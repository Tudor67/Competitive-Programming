class Solution {
private:
    void skipX(const string& S, int& pos, const int& N){
        while(pos < N && S[pos] == 'X'){
            pos += 1;
        }
    }
    
public:
    bool canTransform(string start, string end) {
        const int N = start.length();
        int i = 0;
        int j = 0;
        while(i < N && j < N){
            skipX(start, i, N);
            skipX(end, j, N);
            if(i < N && j < N){
                if(start[i] != end[j] || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)){
                    return false;
                }
                i += 1;
                j += 1;
            }

        }
        skipX(start, i, N);
        skipX(end, j, N);
        return (i == N && j == N);
    }
};