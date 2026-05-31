class Solution {
public:
    bool asteroidsDestroyed(int planetMass, vector<int>& asteroids) {
        const int N = asteroids.size();

        vector<int> sortedAsteroids = asteroids;
        sort(sortedAsteroids.begin(), sortedAsteroids.end());

        long long currPlanetMass = planetMass;
        for(int asteroidMass: sortedAsteroids){
            if(currPlanetMass >= asteroidMass){
                currPlanetMass += asteroidMass;
            }else{
                return false;
            }
        }

        return true;
    }
};