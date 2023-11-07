class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;

        int num = 1;
        for(int targetNum: target){
            while(num < targetNum){
                ops.push_back("Push");
                ops.push_back("Pop");
                num += 1;
            }
            ops.push_back("Push");
            num += 1;
        }

        return ops;
    }
};