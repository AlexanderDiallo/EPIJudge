#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

void MergeTwoSortedArrays(vector<int>& A, int m, const vector<int>& B, int n) {
  // TODO - you fill in here.

    int aIndex = m - 1;
    int bIndex = n - 1;

	int index = A.size() - 1;

	while(aIndex >= 0 || bIndex >= 0)
	{
		if(bIndex < 0
			|| (aIndex >= 0 && A[aIndex] > B[bIndex]))
		{
			A[index] = A[aIndex];
			aIndex--;
			index--;
		}
		else
		{
			A[index] = B[bIndex];
			bIndex--;
			index--;
		}
	}
	
  return;
}
vector<int> MergeTwoSortedArraysWrapper(vector<int> A, int m,
                                        const vector<int>& B, int n) {
  MergeTwoSortedArrays(A, m, B, n);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "m", "B", "n"};
  return GenericTestMain(
      args, "two_sorted_arrays_merge.cc", "two_sorted_arrays_merge.tsv",
      &MergeTwoSortedArraysWrapper, DefaultComparator{}, param_names);
}
