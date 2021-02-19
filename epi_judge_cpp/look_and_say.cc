#include <string>

#include "test_framework/generic_test.h"
using std::string;

string LookAndSay(int n) {
  // TODO - you fill in here.

	string result = "1";

	for(int m = 1; m < n; m++)
	{
		string tempResult;
		for(int i = 0; i < result.size(); i++)
		{
			int count = 1;
			while(i + 1 < result.size() && result[i] == result[i + 1])
			{
				i++; count++;
			}

			tempResult += std::to_string(count) + result[i];
		}

		result = tempResult;
	}
	
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "look_and_say.cc", "look_and_say.tsv",
                         &LookAndSay, DefaultComparator{}, param_names);
}
