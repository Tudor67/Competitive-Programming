class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        
        // Step 1: compute min and max indices of each num
        unordered_map<int, int> minIndexOf;
        unordered_map<int, int> maxIndexOf;
        for(int i = 0; i < N; ++i){
            if(!minIndexOf.count(nums[i])){
                minIndexOf[nums[i]] = i;
            }
            maxIndexOf[nums[i]] = i;
        }
        
        // Step 2: create segments of type {minIndexOf[num], maxIndexOf[num]} for each num
        vector<pair<int, int>> segments;
        segments.reserve(minIndexOf.size());
        for(const pair<const int, int>& P: minIndexOf){
            int num = P.first;
            int l = P.second;
            int r = maxIndexOf[num];
            segments.push_back({l, r});
        }
        
        // Step 3: sort the created segments
        sort(segments.begin(), segments.end());
        
        // Step 4: merge all intersecting segments
        //         and
        //         compute the number of remaining disjoint segments
        int disjointSegments = 1;
        int r = segments[0].second;
        for(const pair<int, int>& SEG: segments){
            if(r < SEG.first){
                disjointSegments += 1;
                r = SEG.second;
            }else{
                r = max(r, SEG.second);
            }
        }
        
        // Step 5: there are 2 ^ (disjointSegments - 1) good partitions of nums
        //         starting with the 2nd disjoint segment we have 2 options:
        //         - unite it with the previous segment;
        //         - don't unite it with the previous segment;
        int res = 1;
        for(int i = 1; i <= disjointSegments - 1; ++i){
            res = (res * 2) % MODULO;
        }
        
        return res;
    }
};