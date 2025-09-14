class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        const int M = languages.size();
        const int E = friendships.size();

        vector<vector<int>> sortedLanguages = languages;
        for(int i = 0; i < M; ++i){
            sort(sortedLanguages[i].begin(), sortedLanguages[i].end());
        }

        vector<int> needsHelp(M, false);
        for(vector<int>& friendship: friendships){
            int a = friendship[0] - 1;
            int b = friendship[1] - 1;

            bool canCommunicate = false;
            for(int aLang: sortedLanguages[a]){
                if(binary_search(sortedLanguages[b].begin(), sortedLanguages[b].end(), aLang)){
                    canCommunicate = true;
                    break;
                }
            }

            if(!canCommunicate){
                needsHelp[a] = true;
                needsHelp[b] = true;
            }
        }
        
        vector<int> freq(n + 1);
        for(int i = 0; i < M; ++i){
            if(needsHelp[i]){
                for(int iLang: sortedLanguages[i]){
                    freq[iLang] += 1;
                }
            }
        }

        return count(needsHelp.begin(), needsHelp.end(), true) - *max_element(freq.begin(), freq.end());
    }
};