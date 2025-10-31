class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        const int N = target.size();

        int minOps = target[0];
        for(int i = 1; i < N; ++i){
            if(target[i] > target[i - 1]){
                minOps += (target[i] - target[i - 1]);
            }
        }

        return minOps;
    }
};