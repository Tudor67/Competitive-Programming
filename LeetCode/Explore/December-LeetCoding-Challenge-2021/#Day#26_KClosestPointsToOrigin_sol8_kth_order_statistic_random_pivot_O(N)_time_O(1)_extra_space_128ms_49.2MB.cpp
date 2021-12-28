class Solution {
private:
    bool isLess(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[0] * LHS[0] + LHS[1] * LHS[1]) < (RHS[0] * RHS[0] + RHS[1] * RHS[1]);
    }
    
    void quickSelect(int L, const int& K, int R, vector<vector<int>>& points){
        bool found = false;
        while(!found){
            int randIdx = L + rand() % (R - L + 1);
            swap(points[randIdx], points[R]);

            vector<int>& pivot = points[R];
            int l = L;
            int r = R - 1;
            while(l <= r){
                if(isLess(points[l], pivot)){
                    ++l;
                }else{
                    swap(points[l], points[r]);
                    --r;
                }
            }

            // points[0 .. pivotIdx - 1] < pivot
            // points[pivotIdx] == pivot
            // pivot <= points[pivotIdx + 1 .. N - 1]
            int pivotIdx = l;
            swap(points[pivotIdx], points[R]);
            if(K == pivotIdx){
                found = true;
            }else if(K < pivotIdx){
                R = pivotIdx - 1;
            }else if(K > pivotIdx){
                L = pivotIdx + 1;
            }
        }
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int N = points.size();
        srand(time(NULL));
        quickSelect(0, k - 1, N - 1, points);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};