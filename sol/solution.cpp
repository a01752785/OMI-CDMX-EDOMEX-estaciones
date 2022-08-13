#include <bits/stdc++.h>
using namespace std;

const int MAX_H = 1000;
const int STREET_SIZE = 1000000;

int num_houses;
int num_hydrants;
int houses[MAX_H];

bool possible(int length) {
	for (int i = 0; i < num_houses; i++) {
		// Number of fire hydrants that are needed.
		int needed = 0;

		// The house that we need to connect a fire hydrant to.
		int start = houses[i];

		for (int j = 1; j < num_houses; j++) {
			// Address of house at index j.
			int end = houses[(i + j) % num_houses];

			/*
			 * If the distance between the start and end houses is greater than two
			 * times the length of the hose, a single fire hydrant will not be
			 * enough to cover both houses.
			 */
			int dist = (end - start + STREET_SIZE) % STREET_SIZE;
			if (dist > 2 * length) {
				start = end;
				needed++;
			}
		}

		// Increment needed as we need another hydrant to reach the last houses.
		needed++;

		if (needed <= num_hydrants) {
			return true;
		}
	}
	return false;
}

int main() {
	cin >> num_houses;
	for (int i = 0; i < num_houses; i++) {
		cin >> houses[i];
	}
	cin >> num_hydrants;

	sort(houses, houses + num_houses);

	// Binary search for the lowest hose length
	int l = 0;
	int r = STREET_SIZE;
	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		if (possible(m)) {
			r = m - 1;
			ans = m;
		} else {
			l = m + 1;
		}
	}
	
	cout << ans << "\n";
}