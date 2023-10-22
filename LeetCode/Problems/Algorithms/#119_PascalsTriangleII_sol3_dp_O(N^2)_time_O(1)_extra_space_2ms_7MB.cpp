class Solution {
public:
    vector<int> getRow(int rowIndex) {
        const int N = rowIndex;

        vector<int> a(N + 1);
        a[0] = 1;
        for(int row = 1; row <= N; ++row){
            for(int col = row; col >= 1; --col){
                a[col] += a[col - 1];
            }
        }

        return a;
    }
};