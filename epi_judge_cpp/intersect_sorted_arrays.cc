#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {

    int aIndex = 0;
    int bIndex = 0;

    std::set<int> result;
	
    while(aIndex < A.size() && bIndex < B.size())
    {
	    if(A[aIndex] < B[bIndex])
	    {
            aIndex++;
	    }
        else if(A[aIndex] > B[bIndex])
        {
            bIndex++;
        }
        else
        {
            result.insert(A[aIndex]);
            aIndex++;
            bIndex++;
        	
        }
    }
	
  // TODO - you fill in here.
  return std::vector<int>(result.begin(), result.end());
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}
