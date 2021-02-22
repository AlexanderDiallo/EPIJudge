#include <string>
#include <ctype.h>

#include "test_framework/generic_test.h"
using std::string;

bool IsPalindrome(const string& s) {
  // TODO - you fill in here.

    int frontIndex = 0;
    int backIndex = s.size() - 1;

	while(frontIndex < backIndex)
	{		
		while(!isalnum(s[frontIndex]) && frontIndex < backIndex)
		{
			frontIndex++;
		}
		while (!isalnum(s[backIndex]) && frontIndex < backIndex)
		{
			backIndex--;
		}

		if(std::toupper(s[frontIndex++]) != std::toupper(s[backIndex--]))
		{
			return false;
		}
	}
	
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_palindromic_punctuation.cc",
                         "is_string_palindromic_punctuation.tsv", &IsPalindrome,
                         DefaultComparator{}, param_names);
}
