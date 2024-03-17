/* Mitsuha is traveling to Tokyo to meet Taki Tachibana. She plans to prepare
Itomori’s best sushi for him, which requires three main ingredients: Bread (B), Salmon
(S), and Corn (C). She expresses her favourite recipe as a string, such as "BBSCS",
meaning Bread, Bread, Salmon, Corn, and Salmon.
Mitsuha has nb pieces of bread, ns pieces of salmon, and nc pieces of corn in her kitchen.
The nearby shop offers all three ingredients (unlimited supply) at prices pb yen for bread,
ps yen for salmon, and pc yen for corn.
With r yen to spend, what is the maximum number of sushi plates she can prepare,
assuming she cannot break or slice any ingredients?
Input:
• Recipe: a string containing only letters B, S, C such that len(string) ≤ 100
• 1 ≤ nb, ns, nc ≤ 100
• 1 ≤ pb, ps, pc ≤ 100
• 1 ≤ r ≤ 1012
Example 1:
Recipe: BBBSSC
n_b = 6, n_s = 4, n_c = 1
p_b = 1, p_s = 2, p_c = 3
r = 4
Output: 2*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to calculate the maximum number of sushi plates that can be prepared
// Parameters:
// - recipe: string representing the recipe
// - nb, ns, nc: number of available bread, salmon, and corn
// - pb, ps, pc: price of bread, salmon, and corn
// - r: budget
// Returns:
// - Maximum number of sushi plates that can be prepared within the budget
long long maxSushiPlates(const string& recipe, int nb, int ns, int nc, int pb, int ps, int pc, long long r) {
    // Count the required ingredients in the recipe by using the pass the reffernce of string to the recipe 
    /*long long data type in the code because the problem specifies that the budget " r " can be as large as 10^12
Using a long long data type ensures that we can handle such large numbers without encountering overflow issues.
*/
    int b = 0, s = 0, c = 0;
    for (char ch : recipe) {
        if (ch == 'B') b++;
        else if (ch == 'S') s++;
        else if (ch == 'C') c++;
    }

    long long plates = 0;
    long long low = 0, high = 1e13;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        // Calculate the cost of preparing 'mid' plates
        long long cost = max(0LL, b * mid - nb) * pb + max(0LL, s * mid - ns) * ps + max(0LL, c * mid - nc) * pc;
        if (cost <= r) {
            plates = max(plates, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return plates;
}

int main() {
    // Example input values
    string recipe = "BBSSC";
    int nb = 6, ns = 4, nc = 1;
    int pb = 1, ps = 2, pc = 3;
    long long r = 4;

    // Calculate and print the maximum number of sushi plates
    long long maxPlates = maxSushiPlates(recipe, nb, ns, nc, pb, ps, pc, r);
    cout << "Maximum number of sushi plates: " << maxPlates << endl;

    return 0;
}
