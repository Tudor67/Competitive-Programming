class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        const int N = words.size();

        for(int delta = 0; delta < N; ++delta){
            for(int i: {(startIndex - delta + N) % N, (startIndex + delta) % N}){
                if(words[i] == target){
                    return delta;
                }
            }
        }

        return -1;
    }
};