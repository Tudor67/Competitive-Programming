class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        const long long MIN_ENERGY = *min_element(enemyEnergies.begin(), enemyEnergies.end());
        const long long ENERGY_SUM = accumulate(enemyEnergies.begin(), enemyEnergies.end(), (long long)0);

        if(currentEnergy < MIN_ENERGY){
            return 0;
        }

        return (currentEnergy + ENERGY_SUM - MIN_ENERGY) / MIN_ENERGY;
    }
};