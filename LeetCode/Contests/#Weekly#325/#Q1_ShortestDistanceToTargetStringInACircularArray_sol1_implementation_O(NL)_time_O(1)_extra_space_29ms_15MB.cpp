class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        const int N = words.size();
        for(int d = 0; d < N; ++d){
            if(target == words[(startIndex - d + N) % N] || target == words[(startIndex + d) % N]){
                return d;
            }
        }
        return -1;
    }
};