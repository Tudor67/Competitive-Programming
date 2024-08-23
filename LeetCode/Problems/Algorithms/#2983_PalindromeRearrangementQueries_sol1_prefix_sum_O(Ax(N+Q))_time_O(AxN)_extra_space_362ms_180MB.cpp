class Solution {
private:
    int getSum(vector<int>& prefSum, int l, int r){
        if(l > r){
            return 0;
        }
        if(l == 0){
            return prefSum[r];
        }
        return prefSum[r] - prefSum[l - 1];
    }
    
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        const int N = s.length();
        const int Q = queries.size();
        const int A = 26;
        
        string s1 = s.substr(0, N / 2);
        string s2 = s.substr(N / 2);
        reverse(s2.begin(), s2.end());
        
        vector<int> mismatchesPrefSum(N / 2);
        mismatchesPrefSum[0] = (int)(s1[0] != s2[0]);
        for(int i = 1; i < N / 2; ++i){
            mismatchesPrefSum[i] = mismatchesPrefSum[i - 1] + (int)(s1[i] != s2[i]);
        }
        
        vector<vector<int>> ps1(A, vector<int>(N / 2));
        vector<vector<int>> ps2(A, vector<int>(N / 2));
        for(int i = 0; i < N / 2; ++i){
            if(i >= 1){
                for(char c = 'a'; c <= 'z'; ++c){
                    ps1[c - 'a'][i] = ps1[c - 'a'][i - 1];
                    ps2[c - 'a'][i] = ps2[c - 'a'][i - 1];
                }
            }
            ps1[s1[i] - 'a'][i] += 1;
            ps2[s2[i] - 'a'][i] += 1;
        }
        
        vector<bool> res(Q);
        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            int l1 = queries[queryIndex][0];
            int r1 = queries[queryIndex][1];
            int l2 = queries[queryIndex][2];
            int r2 = queries[queryIndex][3];

            l2 -= N / 2;
            r2 -= N / 2;
            l2 = N / 2 - 1 - l2;
            r2 = N / 2 - 1 - r2;
            swap(l2, r2);
            
            int li = max(l1, l2);
            int ri = min(r1, r2);

            res[queryIndex] = true;
            if(getSum(mismatchesPrefSum, 0, min(l1, l2) - 1) +
               getSum(mismatchesPrefSum, max(r1, r2) + 1, N / 2 - 1) +
               getSum(mismatchesPrefSum, min(r1, r2) + 1, max(l1, l2) - 1) >= 1){
                res[queryIndex] = false;
            }

            for(char c = 'a'; c <= 'z' && res[queryIndex]; ++c){
                if(li <= ri){
                    int f1 = getSum(ps1[c - 'a'], l1, r1);
                    f1 -= getSum(ps2[c - 'a'], l1, li - 1);
                    f1 -= getSum(ps2[c - 'a'], ri + 1, r1);

                    int f2 = getSum(ps2[c - 'a'], l2, r2);
                    f2 -= getSum(ps1[c - 'a'], l2, li - 1);
                    f2 -= getSum(ps1[c - 'a'], ri + 1, r2);

                    if(f1 != f2 || f1 < 0){
                        res[queryIndex] = false;
                    }
                }else{
                    int f1 = getSum(ps1[c - 'a'], l1, r1);
                    int f1Target = getSum(ps2[c - 'a'], l1, r1);
                    int f2 = getSum(ps2[c - 'a'], l2, r2);
                    int f2Target = getSum(ps1[c - 'a'], l2, r2);

                    if(f1 != f1Target || f2 != f2Target){
                        res[queryIndex] = false;
                    }
                }
            }
        }
        
        return res;
    }
};