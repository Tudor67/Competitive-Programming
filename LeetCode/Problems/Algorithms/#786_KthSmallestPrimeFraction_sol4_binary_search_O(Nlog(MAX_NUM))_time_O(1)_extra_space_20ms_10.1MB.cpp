class Solution {
private:
    double fractionVal(const int& P, const int& Q){
        return ((double)P / (double)Q);
    }
    
    int countFractionsLessOrEqualThan(const double& VAL, const vector<int>& A, const int& N){
        int cnt = 0;
        for(int i = 0, j = 1; i < N && j < N; ++i){
            j = max(i + 1, j);
            while(j < N && fractionVal(A[i], A[j]) > VAL){
                j += 1;
            }
            cnt += (N - j);
        }
        return cnt;
    }
    
    vector<int> findClosestFraction(const double& VAL, const vector<int>& A, const int& N){
        vector<int> closestFraction = {A[0], A[N - 1]};
        for(int i = 0, j = 1; i < N && j < N; ++i){
            j = max(i + 1, j);
            while(j < N && fractionVal(A[i], A[j]) > VAL){
                j += 1;
            }
            if(j < N && fractionVal(A[i], A[j]) > fractionVal(closestFraction[0], closestFraction[1])){
                closestFraction = {A[i], A[j]};
            }
        }        
        return closestFraction;
    }
    
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        // I suppose that all nums from A are unique
        // countFractionLessOrEqualThan(val, A, N) does not work properly if A contains duplicates
        const int N = A.size();
        double val = -1;
        
        double l = 0;
        double r = 1;
        while(l != r){
            double mid = (l + r) / 2;
            int cnt = countFractionsLessOrEqualThan(mid, A, N);
            if(cnt == K){
                val = mid;
                break;
            }else if(cnt < K){
                l = mid;
            }else if(cnt > K){
                r = mid;
            }
        }
        
        return findClosestFraction(val, A, N);
    }
};