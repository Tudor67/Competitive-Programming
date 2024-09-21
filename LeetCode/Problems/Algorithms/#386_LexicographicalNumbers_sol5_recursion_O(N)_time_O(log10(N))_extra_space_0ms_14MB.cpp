class Solution {
private:
    void generate(int level, int num, int n, vector<int>& res){
        for(int digit = !level; digit <= 9; ++digit){
            int nextNum = num * 10 + digit;
            if(nextNum <= n){
                res.push_back(nextNum);
                generate(level + 1, nextNum, n, res);
            }
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        generate(0, 0, n, res);
        return res;
    }
};