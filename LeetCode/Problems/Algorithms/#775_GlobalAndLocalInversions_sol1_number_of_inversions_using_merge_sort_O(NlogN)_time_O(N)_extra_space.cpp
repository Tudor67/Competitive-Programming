class Solution {
private:
    vector<int> temp;
    
    void globalInversions(vector<int>& A, const int& L, const int& R, int& inv){
        const int SIZE = R - L + 1;
        const int MID = (R + L) / 2;
        if(SIZE >= 2){
            globalInversions(A, L, MID, inv);
            globalInversions(A, MID + 1, R, inv);
            temp.resize(max(SIZE, (int)temp.size()));
            for(int k = 0, i = L, j = MID + 1; k < SIZE; ++k){
                if(j > R || (i <= MID && A[i] <= A[j])){
                    temp[k] = A[i++];
                }else{
                    inv += (MID + 1 - i);
                    temp[k] = A[j++];
                }
            }
            copy(temp.begin(), temp.begin() + SIZE, A.begin() + L);
        }
    }
    
    int globalInversions(vector<int>& A){
        const int N = A.size();
        int inv = 0;
        globalInversions(A, 0, N - 1, inv);
        return inv;
    }
    
    int localInversions(const vector<int>& A){
        int inv = 0;
        for(int i = 0; i < (int)A.size() - 1; ++i){
            inv += (A[i] > A[i + 1]);
        }
        return inv;
    }
    
public:
    bool isIdealPermutation(vector<int>& A) {
        vector<int> ACopy = A;
        return (localInversions(A) == globalInversions(ACopy));
    }
};