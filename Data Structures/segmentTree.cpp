/*
* Segment Tree
* Find the minimum element in a given range
* Update the value of an element at a specific index
*/
#include <bits/stdc++.h>
using namespace std;

int nextPowerOf2(int n) {
	if (n == 0)
		return 1;
	if ((n & (n - 1)) == 0)
		return n;
	while ((n & (n - 1)) > 0)
		n &= (n - 1);
	return (n << 1);
}

void constructTree(vector<int> &segmentTree, vector<int> &input, int low, int high, int pos) {
	if (low == high) {
		segmentTree[pos] = input[low];
		return;
	}
	int mid = (low + high) / 2;
	constructTree(segmentTree, input, low, mid, 2 * pos + 1);
	constructTree(segmentTree, input, mid + 1, high, 2 * pos + 2);
	segmentTree[pos] = min(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
}

vector<int> createSegmentTree(vector<int> &input) {
	int n = nextPowerOf2(input.size());
	// Resize the input to its next power of 2 and fill it will dummy values
	for (int i = input.size(); i < n; i++)
		input.push_back(INT_MAX);
	vector<int> segmentTree(2 * n - 1, INT_MAX);
	constructTree(segmentTree, input, 0, input.size() - 1, 0);
	return segmentTree;
}

int minRangeQueryUtil(vector<int> &segmentTree, int low, int high, int qLow, int qHigh, int pos) {
	if (qLow <= low && qHigh >= high)
		return segmentTree[pos];
	if (qHigh < low || qLow > high)
		return INT_MAX;
	int mid = (low + high) / 2;
	return min(minRangeQueryUtil(segmentTree, low, mid, qLow, qHigh, 2 * pos + 1), minRangeQueryUtil(segmentTree, mid + 1, high, qLow, qHigh, 2 * pos + 2));
}

int minRangeQuery(vector<int> &segmentTree, int qLow, int qHigh, int len) {
	return minRangeQueryUtil(segmentTree, 0, len - 1, qLow, qHigh, 0);
}

void updateValueUtil(vector<int> &segmentTree, int low, int high, int value, int index, int pos) {
	if (low > index || high < index)
		return;
	segmentTree[pos] = min(segmentTree[pos], value);
	if (low >= high)
		return;
	int mid = (low + high) / 2;
	updateValueUtil(segmentTree, low, mid, value, index, 2 * pos + 1);
	updateValueUtil(segmentTree, mid + 1, high, value, index, 2 * pos + 2);
}

void updateValue(vector<int> &input, vector<int> &segmentTree, int newValue, int index) {
	input[index] = newValue;
	updateValueUtil(segmentTree, 0, input.size() - 1, newValue, index, 0);
}

int main(void) {
	vector<int> input{1, 3, 5, 7, 9, 11};
	vector<int> segmentTree = createSegmentTree(input);
	for (int i : segmentTree)
		cout << i << ' ';
	cout << endl;
	cout << minRangeQuery(segmentTree, 2, 5, input.size()) << endl;
	cout << minRangeQuery(segmentTree, 1, 3, input.size()) << endl;
	updateValue(input, segmentTree, 4, 3);
	cout << minRangeQuery(segmentTree, 2, 5, input.size()) << endl;
	cout << minRangeQuery(segmentTree, 1, 3, input.size()) << endl;
}





/*
* Segment Tree
* Calculating sum of the elements in a given range
* Update the value of an element at a specific index
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int nextPowerOf2(int n) {
	if (n == 0)
        return 1;
    if ((n & (n - 1)) == 0)
        return n;
    while ((n & (n - 1)) > 0)
        n &= (n - 1);
    return (n << 1);
}

void constructTree(vector<int> &segmentTree, vector<int> &input, int low, int high, int pos) {
	if (low == high) {
		segmentTree[pos] = input[low];
		return;
	}
	int mid = (low + high) / 2;
	constructTree(segmentTree, input, low, mid, 2 * pos + 1);
	constructTree(segmentTree, input, mid + 1, high, 2 * pos + 2);
	segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
}

vector<int> createSegmentTree(vector<int> &input) {
	int n = nextPowerOf2(input.size());
	// Resize to its next power of 2 and fill it with dummy values
	for (int i = input.size(); i < n; i++)
		input.push_back(0);
	vector<int> segmentTree(2 * n - 1, 0);
	constructTree(segmentTree, input, 0, input.size() - 1, 0);
	return segmentTree;
}

int sumRangeQueryUtil(vector<int> &segmentTree, int low, int high, int qLow, int qHigh, int pos) {
	if (qLow <= low && qHigh >= high)
		return segmentTree[pos];
	if (qHigh < low || qLow > high)
		return 0;
	int mid = (low + high) / 2;
	return sumRangeQueryUtil(segmentTree, low, mid, qLow, qHigh, 2 * pos + 1) + sumRangeQueryUtil(segmentTree, mid + 1, high, qLow, qHigh, 2 * pos + 2);
}

int sumRangeQuery(vector<int> &segmentTree, int qLow, int qHigh, int len) {
	return sumRangeQueryUtil(segmentTree, 0, len - 1, qLow, qHigh, 0);
}

void updateValueUtil(vector<int> &segmentTree, int low, int high, int diff, int index, int pos) {
	if (low > index || high < index)
		return;
	segmentTree[pos] += diff;
	if (low >= high)
		return;
	int mid = (low + high) / 2;
	updateValueUtil(segmentTree, low, mid, diff, index, 2 * pos + 1);
	updateValueUtil(segmentTree, mid + 1, high, diff, index, 2 * pos + 2);
}

void updateValue(vector<int> &input, vector<int> &segmentTree, int newValue, int index) {
	int diff = newValue - input[index];
	input[index] = newValue;
	updateValueUtil(segmentTree, 0, input.size() - 1, diff, index, 0);
}

int main(void) {
	vector<int> input{1, 3, 5, 7, 9, 11};
	vector<int> segmentTree = createSegmentTree(input);
	for (int i : segmentTree)
		cout << i << ' ';
	cout << endl;
	cout << sumRangeQuery(segmentTree, 2, 5, input.size()) << endl;
	cout << sumRangeQuery(segmentTree, 1, 3, input.size()) << endl;
	updateValue(input, segmentTree, 4, 3);
	cout << sumRangeQuery(segmentTree, 2, 5, input.size()) << endl;
	cout << sumRangeQuery(segmentTree, 1, 3, input.size()) << endl;
}
