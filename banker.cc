/*
	g++ -o banker.exe banker.cc
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// Increments bits if possible, returning false when no more enumerations exist.
// Each call O(bits.size()), amortized O(1).
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

int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " n" << endl;
    exit(1);
  }
  int length = atoi(argv[1]);
  vector<int> bits;
  do {
    Print(length, bits);
  } while (Increment(length, bits));
  return 0;
}
