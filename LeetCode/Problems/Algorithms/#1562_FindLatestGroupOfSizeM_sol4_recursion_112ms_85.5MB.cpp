class Solution {
private:
    void solve(vector<int>& arr, int l, int r, int idx, int m, int& answer){
        if(idx < 0 || r - l - 1 < m){
            // stop
        }else if(r - l - 1 == m){
            answer = max(idx + 1, answer);
        }else{
            int pos = arr[idx] - 1;
            if(l < pos && pos < r){
                solve(arr, l, pos, idx - 1, m, answer);
                solve(arr, pos, r, idx - 1, m, answer);
            }else{
                solve(arr, l, r, idx - 1, m, answer);
            }
        }
    }
    
public:
    int findLatestStep(vector<int>& arr, int m) {
        const int N = arr.size();
        int answer = -1;
        solve(arr, -1, N, N - 1, m, answer);
        return answer;
    }
};