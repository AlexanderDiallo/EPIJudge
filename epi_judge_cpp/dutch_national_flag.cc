#include <array>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::vector;
enum class Color { kRed, kWhite, kBlue };

void DutchFlagPartition(int pivot_index, vector<Color>* A_ptr) {
  // TODO - you fill in here.

    vector<Color>& colors = *A_ptr;
    Color pivot = colors[pivot_index];
	
	/*for(int i = 0; i < colors.size(); i++)
	{
        for (int j = 0; j < colors.size(); j++)
        {
        	if(colors[j] > colors[i])
        	{
                std::swap(colors[j], colors[i]);
                break;
        	}
        }
	}

    for (int i = colors.size() - 1; i >= 0; i--)
    {
        for (int j = colors.size() - 1; j >= 0; j--)
        {
            if (colors[j] < colors[i])
            {
                std::swap(colors[j], colors[i]);
                break;
            }
        }
    }*/

    /*int smaller = 0;
    int larger = colors.size() - 1;
	
    for (int i = 0; i < colors.size(); i++)
    {
        if(colors[i] < pivot)
        {
            std::swap(colors[smaller], colors[i]);
            smaller++;
        }
    }

    for (int i = colors.size() - 1; i >= 0; i--)
    {
        if (colors[i] > pivot)
        {
            std::swap(colors[larger], colors[i]);
            larger--;
        }
    }*/

    int smaller = 0;
    int equal = 0;
    int larger = colors.size();

	while(equal < larger)
	{
		if(colors[equal] < pivot)
		{
            std::swap(colors[equal], colors[smaller]);
            smaller++;
            equal++;
		}
        else if (colors[equal] == pivot)
        {
            equal++;
        }
        else if (colors[equal] > pivot)
        {
            larger--;
            std::swap(colors[equal], colors[larger]);
        }
	}
	
	
  return;
}
void DutchFlagPartitionWrapper(TimedExecutor& executor, const vector<int>& A,
                               int pivot_idx) {
  vector<Color> colors;
  colors.resize(A.size());
  std::array<int, 3> count = {0, 0, 0};
  for (size_t i = 0; i < A.size(); i++) {
    count[A[i]]++;
    colors[i] = static_cast<Color>(A[i]);
  }
  Color pivot = colors[pivot_idx];

  executor.Run([&] { DutchFlagPartition(pivot_idx, &colors); });

  int i = 0;
  while (i < colors.size() && colors[i] < pivot) {
    count[static_cast<int>(colors[i])]--;
    ++i;
  }

  while (i < colors.size() && colors[i] == pivot) {
    count[static_cast<int>(colors[i])]--;
    ++i;
  }

  while (i < colors.size() && colors[i] > pivot) {
    count[static_cast<int>(colors[i])]--;
    ++i;
  }

  if (i != colors.size()) {
    throw TestFailure("Not partitioned after " + std::to_string(i) +
                      "th element");
  } else if (count != std::array<int, 3>{0, 0, 0}) {
    throw TestFailure("Some elements are missing from original array");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A", "pivot_idx"};
  return GenericTestMain(args, "dutch_national_flag.cc",
                         "dutch_national_flag.tsv", &DutchFlagPartitionWrapper,
                         DefaultComparator{}, param_names);
}
