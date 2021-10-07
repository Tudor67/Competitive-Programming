class Solution {
private:
    const int N;
    set<int> invalid_nums;
    
public:
    Solution(int N, vector<int>& blacklist): N(N) {
        invalid_nums = set<int>(blacklist.begin(), blacklist.end());
    }
    
    int pick() {
        int num = 0;
        do{
            num = rand() % N;
        }while(invalid_nums.count(num));
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */