#include <bits/stdc++.h>
using namespace std;

// For positive integers a, b, and c such that a < b < c,
// a, b, and c form a triangle if the triangle inequality is satisfied:
// - a < b + c (always satisfied, because a < b)
// - b < a + c (always satisfied, because b < c)
// - c < a + b
//
// Thus, given a and b, valid choices for c satisfy 
// b < c < a + b
// 
// For any valid choice of c, we can apply the Pythagorean Theorem
// to determine if the triangle is acute, right, or obtuse:
// - If a^2 + b^2 > c^2, then a, b, and c form an acute triangle.
// - If a^2 + b^2 = c^2, then a, b, and c form a right triangle.
// - If a^2 + b^2 < c^2, then a, b, and c form an obtuse triangle.


void solve() {
	int n;
	cin >> n;

	vector<int> sticks(n);
	map<int, int> squares;

	for (int& x : sticks) {
		cin >> x;

		squares[x * x] = x;
	}

	// let's insert something massive (larger than any stick we might be given)
	// to make our lives easier
	squares[10000 * 10000] = 10000;

	sort(sticks.begin(), sticks.end());

	// count the number of c's that form acute triangles with a and b
	auto countAcute = [&](int a, int b) {
		int lo = b + 1; // minimum value for c
		int hi = a + b - 1; // maximum value for c

		// find the smallest c we have such that a^2 + b^2 <= c^2
		auto it = squares.lower_bound(a * a + b * b);
		hi = min(hi, it->second - 1);

		if (lo > hi)
			return 0;

		int left = lower_bound(sticks.begin(), sticks.end(), lo) - sticks.begin();
		int right = upper_bound(sticks.begin(), sticks.end(), hi) - sticks.begin();
		return right - left;
	};

	// count the number of c's that form right triangles with a and b
	// in this case, there's only zero or one, so we can just check if we have it or not
	auto countRight = [&](int a, int b) {
		return squares.count(a * a + b * b);
	};

	// count the number of c's that form obtuse triangles with a and b
	auto countObtuse = [&](int a, int b) {
		int lo = b + 1; // minimum value for c
		int hi = a + b - 1; // maximum value for c

		// find the smallest c we have such that a^2 + b^2 < c^2
		auto it = squares.upper_bound(a * a + b * b);
		lo = max(lo, it->second);
		
		if (lo > hi)
			return 0;

		int left = lower_bound(sticks.begin(), sticks.end(), lo) - sticks.begin();
		int right = upper_bound(sticks.begin(), sticks.end(), hi) - sticks.begin();
		return right - left;
	};

	int acute = 0, right = 0, obtuse = 0;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			acute += countAcute(sticks[i], sticks[j]);
			right += countRight(sticks[i], sticks[j]);
			obtuse += countObtuse(sticks[i], sticks[j]);
		}

	cout << acute << " " << right << " " << obtuse << '\n';
}

int main() {
	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}
