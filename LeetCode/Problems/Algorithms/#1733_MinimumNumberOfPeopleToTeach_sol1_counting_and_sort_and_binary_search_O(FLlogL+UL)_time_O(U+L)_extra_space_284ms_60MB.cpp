class Solution {
private:
    bool intersects(vector<int>& a, vector<int>& b){
        sort(b.begin(), b.end());
        for(int elem: a){
            if(binary_search(b.begin(), b.end(), elem)){
                return true;
            }
        }
        return false;
    }

public:
    int minimumTeachings(int L, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        const int U = languages.size();
        const int F = friendships.size();

        vector<bool> isGood(U + 1, true);
        for(const vector<int>& V: friendships){
            int a = V[0];
            int b = V[1];
            if(!intersects(languages[a - 1], languages[b - 1])){
                isGood[a] = false;
                isGood[b] = false;
            }
        }

        int badUsers = 0;
        int maxCount = 0;
        unordered_map<int, int> count;
        for(int user = 1; user <= U; ++user){
            if(!isGood[user]){
                badUsers += 1;
                for(int language: languages[user - 1]){
                    count[language] += 1;
                    maxCount = max(maxCount, count[language]);
                }
            }
        }

        return badUsers - maxCount;
    }
};