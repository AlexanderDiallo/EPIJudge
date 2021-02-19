#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> PlusOne(vector<int> A) {
  // TODO - you fill in here.

	for(int i = A.size() - 1; i >= 0; i--)
	{
		A[i] = (A[i] + 1) % 10;
		if(A[i] != 0)
		{
			break;
		}

		if(i == 0)
		{
			A.emplace(std::begin(A), 1);
		}
	}
	
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
