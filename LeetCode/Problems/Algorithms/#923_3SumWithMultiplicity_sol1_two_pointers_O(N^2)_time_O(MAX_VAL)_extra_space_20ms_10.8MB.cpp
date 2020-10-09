class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        const int N = A.size();
        const int MAX_VAL = *max_element(A.begin(), A.end());
        const int MODULO = 1e9 + 7;
        
        sort(A.begin(), A.end());
        
        vector<int> cnt(MAX_VAL + 1);
        for(int elem: A){
            cnt[elem] += 1;
        }
        
        int answer = 0;
        for(int p1 = 0; p1 < N - 2; ++p1){
            if(p1 > 0 && A[p1 - 1] == A[p1]){
                continue;
            }
            int p2 = p1 + 1;
            int p3 = N - 1;
            while(p2 < p3){
                if(p2 > p1 + 1 && A[p2 - 1] == A[p2]){
                    p2 += 1;
                    continue;
                }
                if(p3 < N - 1 && A[p3] == A[p3 + 1]){
                    p3 -= 1;
                    continue;
                }
                int currentSum = A[p1] + A[p2] + A[p3];
                if(currentSum < target){
                    p2 += 1;
                }else if(currentSum > target){
                    p3 -= 1;
                }else if(currentSum == target){
                    long long ways = 0;
                    if(A[p1] == A[p2] && A[p2] == A[p3]){
                        long long x = cnt[A[p1]];
                        ways = (x - 2) * (x - 1) * x / 6;
                    }else if(A[p1] == A[p2] && A[p2] != A[p3]){
                        long long x = cnt[A[p1]];
                        ways = (x - 1) * x * cnt[A[p3]] / 2;
                    }else if(A[p1] != A[p2] && A[p2] == A[p3]){
                        long long x = cnt[A[p2]];
                        ways = cnt[A[p1]] * (x - 1) * x / 2;
                    }else if(A[p1] != A[p2] && A[p2] != A[p3]){
                        ways = cnt[A[p1]] * cnt[A[p2]] * cnt[A[p3]];
                    }
                    answer += (ways % MODULO);
                    answer %= MODULO;
                    p2 += 1;
                    p3 -= 1;
                }
            }
        }
        
        return answer;
    }
};