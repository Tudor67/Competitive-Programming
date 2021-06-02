class Solution {
public:
    int bulbSwitch(int n) {
        // Initially, all bulbs are `off`.
        // If a bulb is toggled an even number of times it remains `off`.
        // If a bulb is toggled an odd number of times it remains `on`.
        //
        // The xth bulb will be toggled k times, where k is the number of divisors of x.
        // Key observations: 1.) toggle operations of xth bulb is equal to the number of divisors of x.
        //                   2.) we are interested in bulbs which will remain `on` <=> bulbs with odd number of divisors.
        //                   3.) bulbs with odd number of divisors <=> bulbs that are perfect squares.
        // 
        // We need to count how many bulbs will be `on` after n rounds.
        // This is equivalent to counting how many bulbs in range [1..n] will be toggled an odd number of times.
        // This is equivalent to counting how many bulbs in range [1..n] have an odd number of divisors.
        // This is equivalent to counting how many bulbs in range [1..n] are perfect squares.
        return sqrt(n);
    }
};