class Solution {
private:
    bool intersects(vector<int>& a, vector<int>& b, vector<bool>& vis){
        for(int elem: a){
            vis[elem] = true;
        }

        bool intersectionFound = false;
        for(int elem: b){
            if(vis[elem]){
                intersectionFound = true;
                break;
            }
        }

        for(int elem: a){
            vis[elem] = false;
        }

        return intersectionFound;
    }

public:
    int minimumTeachings(int L, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        const int U = languages.size();
        const int F = friendships.size();

        vector<bool> isGood(U + 1, true);
        vector<bool> tempVis(L + 1, false);
        for(const vector<int>& V: friendships){
            int a = V[0];
            int b = V[1];
            if(!intersects(languages[a - 1], languages[b - 1], tempVis)){
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