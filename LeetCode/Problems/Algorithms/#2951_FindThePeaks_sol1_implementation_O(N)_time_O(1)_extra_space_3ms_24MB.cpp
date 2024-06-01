class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        const int N = mountain.size();

        vector<int> peaks;
        for(int i = 1; i + 1 < N; ++i){
            if(mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]){
                peaks.push_back(i);
            }
        }

        return peaks;
    }
};