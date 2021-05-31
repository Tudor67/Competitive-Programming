class Solution {
private:
    void back(int row, const int& N, int visColMask, int visMainDiagMask, int visSecDiagMask, int& answer){
        if(row == N){
            answer += 1;
        }else{
            for(int col = 0; col < N; ++col){
                int mainDiag = row - col + N - 1;
                int secDiag = row + col;
                if(!((visColMask >> col) & 1) && !((visMainDiagMask >> mainDiag) & 1) && !((visSecDiagMask >> secDiag) & 1)){
                    back(row + 1, N, visColMask | (1 << col), visMainDiagMask | (1 << mainDiag), visSecDiagMask | (1 << secDiag), answer);
                }
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        int answer = 0;
        back(0, n, 0, 0, 0, answer);
        return answer;
    }
};