class Solution {
private:
    const int INF = 1e9;

    int computeNumberOfBoxes(vector<int>& f, int minSize){
        int totalBoxes = 0;
        for(int currentFreq: f){
            int currentBoxes = currentFreq / (minSize + 1);
            int rem = currentFreq % (minSize + 1);
            if(rem == 0){
                totalBoxes += currentBoxes;
            }else if(rem + currentBoxes >= minSize){
                totalBoxes += currentBoxes;
                totalBoxes += 1;
            }else{
                return INF;
            }
        }
        return totalBoxes;
    }

public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        const int N = balls.size();
        
        unordered_map<int, int> freqOf;
        for(int ball: balls){
            freqOf[ball] += 1;
        }

        vector<int> f;
        f.reserve(freqOf.size());
        for(const pair<const int, int>& P: freqOf){
            f.push_back(P.second);
        }

        const int MIN_FREQ = *min_element(f.begin(), f.end());
        for(int minSize = MIN_FREQ; minSize >= 1; --minSize){
            int totalBoxes = computeNumberOfBoxes(f, minSize);
            if(totalBoxes != INF){
                return totalBoxes;
            }
        }

        return N;
    }
};