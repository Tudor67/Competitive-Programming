class Solution {
public:
    int numRabbits(vector<int>& answers) {
        const int N = answers.size();

        int totalRabbits = 0;
        unordered_map<int, int> f;

        for(int i = 0; i < N; ++i){
            int x = answers[i] + 1;
            f[x] += 1;
            if(f[x] == x){
                f.erase(x);
                totalRabbits += x;
            }
        }

        for(auto& [x, _]: f){
            totalRabbits += x;
        }

        return totalRabbits;
    }
};