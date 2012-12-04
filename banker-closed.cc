#include <tr1/unordered_map>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
using namespace tr1;

// Returns the value of nCk, memoizing the result to make repeated calls
// efficient.
int64_t Choose(int n, int k) {
  k = min(k, n-k);  // Symmetric values.
  static unordered_map<int64_t, int64_t> cache;
  int64_t key = (static_cast<int64_t>(n) << 32) ^ k;
  if (cache.count(key) == 0) {
    if (k == 0) {
      cache[key] = 1;
    } else {
      cache[key] = Choose(n-1, k) + Choose(n-1, k-1);
    }
  }
  return cache[key];
}

// Returns the i'th subset of size k of n bits. If offset > 0 output bits are
// incremented by offset, to support recursion.
// O(n) (actually, O(bits.size()) for output bits), assuming Choose() values
// already cached.
bool SubsetWithK(int n, int k, int64_t i, int offset, vector<int>& bits) {
  if (i >= Choose(n, k)) {
    return false;  // Above upper bound.
  }
  int zeros = 0;
  int64_t low = 0;
  int64_t high = Choose(n-1, k-1);
  while (i >= high) {
    zeros += 1;
    low = high;
    high += Choose(n-zeros-1, k-1);
  }
  bits.push_back(zeros + offset);
  if (k == 1) {
    return true;
  } else {
    return SubsetWithK(n-zeros-1, k-1, i-low, offset+zeros+1, bits);
  }
}

// Returns the i'th subset of n bits.
// O(n) (actually, O(bits.size()) for output bits), assuming Choose() values
// already cached.
bool Subset(int n, int64_t i, vector<int>& bits) {
  if (i >= (1ll << n)) {  // 2^n subsets total.
    return false;
  }
  bits.clear();
  if (i == 0) {
    return true;
  }
  int64_t low = 0;
  int64_t high = 1;  // Choose(n, 0).
  int k = 0;
  while (i >= high) {
    k += 1;
    low = high;
    high += Choose(n, k);
  }
  return SubsetWithK(n, k, i-low, 0, bits);
}

// Increments the input bits to be the next subset from n, returning false when
// no more enumerations exist.
// Each call O(bits.size()), amortized O(1) when enumerating all subsets of n.
bool Increment(int n, vector<int>& bits) {
  if (bits.size() >= n) {
    return false;
  }
  const int k = bits.size();
  for (int i = k - 1; i >= 0; --i) {
    // For each bit, move if possible, and then reset trailing bits.
    if (bits[i] < n - k + i) {
      bits[i] += 1;
      for (int j = i + 1; j < k; ++j) {
        bits[j] = bits[j-1] + 1;
      }
      return true;
    }
  }
  // Start again with one more bit.
  for (int i = 0; i < k; ++i) {
    bits[i] = i;
  }
  bits.push_back(k);
  return true;
}

// Prints the full bit string the passed-in bits represent. O(n).
void Print(int n, const vector<int>& bits) {
  int last = -1;
  for (int i = 0; i < bits.size(); ++i) {
    cout << string(bits[i] - last - 1, '0') << "1";
    last = bits[i];
  }
  cout << string(n - last - 1, '0') << "\n";
}

// Computes the Banker's sequence for a given number of bits in two ways: once 
// through successive incrementing, once via direct computation from the subset
// index. Compares at each step to ensure the results are the same, and prints
// one copy.
int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " n" << endl;
    return 1;
  }
  int length = atoi(argv[1]);
  vector<int> increment_bits;  // Computed via successive Increment calls.
  int index = 0;
  do {
    vector<int> direct_bits;  // Computed directly from subset index.
    if (!Subset(length, index++, direct_bits) ||
        increment_bits != direct_bits) {
      cout << "Error: mismatch on index " << index << endl;
      return 1;
    }
    Print(length, increment_bits);
  } while (Increment(length, increment_bits));
  return 0;
}
