/*
* Binary Indexed Tree (Fenwick Tree) to do the following operations in O(log n) time complexity
* To calculate sum of first n numbers
* To update a value at the given pos
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void update(vector<int> &BITree, int pos, int n, int val) {
	while (pos <= n) {
		BITree[pos] += val;
		pos += (pos & -pos);
	}
}

int query(vector<int> &BITree, int pos) {
	int sum = 0;
	while (pos) {
		sum += BITree[pos];
		pos -= (pos & -pos);
	}
	return sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n), BITree(n+1, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		update(BITree, i+1, n, v[i]);
	}
	int q;
	cin >> q;
	while (q--) {
		int ty, pos, val;
		cin >> ty;
		if (ty == 1) {
			cin >> pos >> val;
			v[pos - 1] += val;
			update(BITree, pos, n, val);
		} else {
			cin >> pos;
			cout << query(BITree, pos) << endl;
		}
	}
}
