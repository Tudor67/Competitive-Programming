class Solution {
private:
    int compress(vector<int>& sortedNums, int val){
        return lower_bound(sortedNums.begin(), sortedNums.end(), val) - sortedNums.begin();
    }

public:
    int intersectionSizeTwo(vector<vector<int>>& originalIntervals) {
        const int N = originalIntervals.size();

        // coordinate compression
        vector<int> sortedNums;
        sortedNums.reserve(2 * N);
        for(vector<int>& interval: originalIntervals){
            sortedNums.push_back(interval[0]);
            sortedNums.push_back(interval[1]);
        }

        sort(sortedNums.begin(), sortedNums.end());
        sortedNums.resize(unique(sortedNums.begin(), sortedNums.end()) - sortedNums.begin());

        vector<array<int, 2>> intervals(N);
        for(int i = 0; i < N; ++i){
            int l = compress(sortedNums, originalIntervals[i][0]);
            int r = compress(sortedNums, originalIntervals[i][1]);
            intervals[i] = {l, r};
        }

        // solve for compressed intervals
        map<int, vector<int>> endToStarts;
        for(int i = 0; i < N; ++i){
            int l = intervals[i][0];
            int r = intervals[i][1];
            endToStarts[r].push_back(l);
        }

        const int MAX_NUM = compress(sortedNums, sortedNums.back());
        vector<bool> taken(MAX_NUM + 1, false);

        set<int> waitingSet;
        for(int num = 0; num <= MAX_NUM; ++num){
            waitingSet.insert(num);
        }

        for(const auto& [r, ls]: endToStarts){
            for(int l: ls){
                while(count(taken.begin() + l, taken.begin() + r + 1, true) < 2){
                    int num = *prev(waitingSet.upper_bound(r));
                    waitingSet.erase(num);
                    taken[num] = true;
                }
            }
        }

        return count(taken.begin(), taken.end(), true);
    }
};