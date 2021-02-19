#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;

string IntToString(int x) {
  // TODO - you fill in here.

    bool isNegative = false;
	if(x < 0)
	{
        isNegative = true;
	}

    string s;
	do
	{
        s.push_back(std::abs(x % 10) + '0');
        x /= 10;

    } while (x);

    if(isNegative)
    {
        s.push_back('-');
    }
	
    return { s.rbegin(), s.rend() };
	
  //return "0";
}
int StringToInt(const string& s) {
  // TODO - you fill in here.

    int number = 0;

	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '-' || s[i] == '+')
		{
            continue;
		}

        int digit = s[i] - '0';
        number = number * 10 + digit;
	}
	
  return s[0] == '-' ? -number : number;
}
void Wrapper(int x, const string& s) {
  if (stoi(IntToString(x)) != x) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}
