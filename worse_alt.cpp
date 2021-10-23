/*

To solve this problem, you can loop through the input string, keeping a count, 0-indexed.
When you reach a space, print the letter corresponding with the current count.
Print the last letter at the end.
We print as we go to avoid possibly costly string operations.

*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Input entire line
    string line; getline(cin, line);

    // Count variable
    int cnt = -1;       
    // For each line
    for (char c : line) {    
        // If there's a space
        if (isspace(c) && cnt >= 0) { 
            // Print the current letter
            cout << (char)(cnt + 'A');
            // Reset the count
            cnt = -1;
        } 
        // If there's no space, increment the count
        else cnt++;
    }

    // Print the last character
    if (cnt >= 0)
        cout << (char)(cnt + 'A');
    cout << '\n';
}

int main() {
    // Test case input
    int t; cin >> t;
    // Get rid of the new line character
    string newline; getline(cin, newline);
    while(t--)
        solve();
    return 0;
}
