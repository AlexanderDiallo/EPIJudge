#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {

    int aIndex = 0;
    int bIndex = 0;

    std::set<int> result;
    std::vector<int> resultAsArray;
	
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
            resultAsArray.push_back(A[aIndex]);

            while(A[aIndex] == resultAsArray.back())
            {
                aIndex++;
                if (aIndex >= A.size()) { break; }
            }
            while (B[bIndex] == resultAsArray.back())
            {
                bIndex++;
                if (bIndex >= B.size()) { break; }
            }
        	
        }
    }
	
  // TODO - you fill in here.
  return resultAsArray;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}
