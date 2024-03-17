/* You are playing Dota2 and are currently in the middle lane, which has n
heroes. Each hero has the following attributes:
• Position: Given as a 0-indexed integer array. All integers are unique. The index
in the array refers to a particular hero, and the value at that index indicates the
position.
• Health: Given as a 0-indexed integer array. The index in the array refers to a
particular hero, and the value at that index indicates the health.
• Team: Given a string (R for radiant, D for Dire).
All heroes move simultaneously at the same speed on the lane, each going in its given
direction. Radiant moves up, and Dire moves down the middle lane. If two heroes ever
meet in the same position, they have a battle. When this happens, the hero with less
health is removed from the lane, and the health of the other hero drops by one. If both
heroes have the same health, they both get removed.
Return an array containing the health of the remaining heroes (in the order they were
given in the input), after no further battle can occur.
Constraint :
• 1 ≤ positions.length, healths.length ≤ 105
• 1 ≤ healths[i], positions[i] ≤ 109 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a struct to represent a hero
struct Hero {
    int position; // Hero's position on the lane
    int health;   // Hero's health points
    Hero(int pos, int hp) : position(pos), health(hp) {}
};

// Function to find the remaining health of heroes after battles
vector<int> remainingHealth(const vector<int>& positions, const vector<int>& healths, const string& team) {
    int n = positions.size(); // Number of heroes
    vector<Hero> heroes; // Vector to store hero objects

    // Create hero objects based on input positions and healths
    for (int i = 0; i < n; i++) {
        heroes.emplace_back(positions[i], healths[i]);
    }

    // Simulate battles until no further battles can occur
    while (true) {
        bool battleOccurred = false; // Flag to track if a battle occurred in the current iteration
        for (int i = 0; i < n - 1; i++) {
            // Check if heroes are from different teams and at the same position
            if (team[i] == team[i + 1]) continue; // Skip if heroes are from the same team
            if (heroes[i].position == heroes[i + 1].position) {
                battleOccurred = true; // Set the flag to true as a battle occurred
                // Resolve the battle based on hero health
                if (heroes[i].health < heroes[i + 1].health) {
                    heroes[i + 1].health -= 1; // Reduce health of hero[i+1]
                    heroes.erase(heroes.begin() + i); // Remove hero[i] from the vector
                    n--; // Decrease the number of heroes
                } else if (heroes[i].health > heroes[i + 1].health) {
                    heroes[i].health -= 1; // Reduce health of hero[i]
                    heroes.erase(heroes.begin() + i + 1); // Remove hero[i+1] from the vector
                    n--; // Decrease the number of heroes
                } else { // Equal health, both heroes are removed
                    heroes.erase(heroes.begin() + i, heroes.begin() + i + 2); // Remove hero[i] and hero[i+1]
                    n -= 2; // Decrease the number of heroes by 2
                }
                break; // Exit the loop after resolving one battle per iteration
            }
        }
        if (!battleOccurred) break; // Exit the loop if no battles occurred in the iteration
    }

    // Extract remaining healths of heroes
    vector<int> remaining;
    for (const auto& hero : heroes) {
        remaining.push_back(hero.health);
    }
    return remaining; // Return the remaining healths of heroes
}

int main() {
    // Example input
    vector<int> positions = {5, 4, 3, 2, 1};
    vector<int> healths = {2, 17, 9, 15, 10};
    string team = "RRRRR";

    // Call the function and get the remaining healths
    vector<int> result = remainingHealth(positions, healths, team);

    // Print the remaining healths
    for (int hp : result) {
        cout << hp << " ";
    }
    cout << endl;

    return 0;
}
