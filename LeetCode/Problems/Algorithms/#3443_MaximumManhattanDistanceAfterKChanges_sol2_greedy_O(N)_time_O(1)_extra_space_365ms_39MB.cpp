class Solution {
public:
    int maxDistance(string s, int k) {
        int maxDist = 0;
        map<char, int> freq;

        for(char c: s){
            freq[c] += 1;

            int dist = abs(freq['N'] - freq['S']) +
                       abs(freq['E'] - freq['W']) +
                       2 * min(k, min(freq['N'], freq['S']) + min(freq['E'], freq['W']));

            maxDist = max(maxDist, dist);
        }

        return maxDist;
    }
};