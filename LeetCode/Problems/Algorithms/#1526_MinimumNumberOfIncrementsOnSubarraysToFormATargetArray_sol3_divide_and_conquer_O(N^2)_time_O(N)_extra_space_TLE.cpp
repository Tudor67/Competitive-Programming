class Solution {
private:
    int solve(vector<int>& a, const int& L, const int& R, int prevOperations){
        if(L > R){
            return 0;
        }
        int minIdx = min_element(a.begin() + L, a.begin() + R + 1) - a.begin();
        int operations = a[minIdx] - prevOperations;
        return operations + solve(a, L, minIdx - 1, a[minIdx]) + solve(a, minIdx + 1, R, a[minIdx]);
    }
    
public:
    int minNumberOperations(vector<int>& target) {
        return solve(target, 0, (int)target.size() - 1, 0);
    }
};