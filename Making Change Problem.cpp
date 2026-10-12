//INPUT
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum number of coins needed
int getMinCoins(const vector<int>& coins, int amount) {
    // Create a DP table to store solutions to subproblems
    // dp[i] will store the minimum coins needed for amount i
    vector<int> dp(amount + 1, INT_MAX);

    // Base case: 0 coins are needed to make an amount of 0
    dp[0] = 0;

    // Iterate through all amounts from 1 to the target amount
    for (int i = 1; i <= amount; i++) {
        // Check every available coin denomination
        for (int coin : coins) {
            // Only consider the coin if its value is less than or equal to current amount i
            if (i >= coin) {
                int subResult = dp[i - coin];
                // Check if the subproblem has a valid solution
                if (subResult != INT_MAX && subResult + 1 < dp[i]) {
                    dp[i] = subResult + 1;
                }
            }
        }
    }

    // If dp[amount] is still INT_MAX, it means the change cannot be formed
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int numCoins, amount;

    // Get user inputs
    cout << "Enter the number of coin denominations available: ";
    if (!(cin >> numCoins) || numCoins <= 0) {
        cout << "Invalid number of coins." << endl;
        return 1;
    }

    vector<int> coins(numCoins);
    cout << "Enter the values of the coins:\n";
    for (int i = 0; i < numCoins; i++) {
        cout << "Coin " << i + 1 << ": ";
        cin >> coins[i];
    }

    cout << "Enter the target amount of change required: ";
    cin >> amount;

    if (amount < 0) {
        cout << "Target amount cannot be negative." << endl;
        return 1;
    }

    // Calculate result
    int result = getMinCoins(coins, amount);

    // Output result
    if (result == -1) {
        cout << "\nIt is impossible to make exact change for " << amount << " with the given coins." << endl;
    } else {
        cout << "\nThe minimum number of coins required to make change is: " << result << endl;
    }

    return 0;
}

//OUTPUT
Enter the number of coin denominations available: 4
Enter the values of the coins:
Coin 1: 1
Coin 2: 4
Coin 3: 6
Coin 4: 9
Enter the target amount of change required: 10

The minimum number of coins required to make change is: 2

