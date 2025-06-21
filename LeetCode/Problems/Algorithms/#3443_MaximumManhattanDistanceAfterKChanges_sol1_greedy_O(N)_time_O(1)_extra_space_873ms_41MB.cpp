class Solution {
private:
    int computeMaxDistance(const string& S, int k, char a, char b, char c, char d){
        // transform (a -> b) and (c -> d) at most k times
        // return the max distance of the new string S
        int maxDist = 0;
        map<char, int> freq;
        
        for(char ch: S){
            if(k >= 1){
                if(ch == a){
                    ch = b;
                    k -= 1;
                }else if(ch == c){
                    ch = d;
                    k -= 1;
                }
            }
            freq[ch] += 1;
            maxDist = max(maxDist, abs(freq['N'] - freq['S']) + abs(freq['E'] - freq['W']));
        }

        return maxDist;
    }

public:
    int maxDistance(string s, int k) {
        int d1 = computeMaxDistance(s, k, 'N', 'S', 'E', 'W');
        int d2 = computeMaxDistance(s, k, 'N', 'S', 'W', 'E');
        int d3 = computeMaxDistance(s, k, 'S', 'N', 'E', 'W');
        int d4 = computeMaxDistance(s, k, 'S', 'N', 'W', 'E');
        return max({d1, d2, d3, d4});
    }
};