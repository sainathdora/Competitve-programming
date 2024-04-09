#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::vector;

void combinations_recursive(const vector<int> &elems, unsigned long req_len,
			    vector<unsigned long> &pos, unsigned long depth,
			    unsigned long margin)
{
	// Have we selected the number of required elements?
	if (depth >= req_len) {
		for (unsigned long ii = 0; ii < pos.size(); ++ii)
			cout << elems[pos[ii]];
		cout << endl;
		return;
	}

	// Are there enough remaining elements to be selected?
	// This test isn't required for the function to be correct, but
	// it can save a good amount of futile function calls.
	if ((elems.size() - margin) < (req_len - depth))
		return;

	// Try to select new elements to the right of the last selected one.
	for (unsigned long ii = margin; ii < elems.size(); ++ii) {
		pos[depth] = ii;
		combinations_recursive(elems, req_len, pos, depth + 1, ii + 1);
	}
	return;
}

void combinations(const vector<int> &elems, unsigned long req_len)
{
	assert(req_len > 0 && req_len <= elems.size());
	vector<unsigned long> positions(req_len, 0);
	combinations_recursive(elems, req_len, positions, 0, 0);
}

const unsigned long num_elements = 7;
const unsigned long comb_len = 6;

int main()
{
	vector<int>elements(1, 2, 3, 4);
	combinations(elements, 3);
	return 0;
}