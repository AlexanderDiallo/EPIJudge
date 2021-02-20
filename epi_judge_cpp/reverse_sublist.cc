#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {


    shared_ptr<ListNode<int>> dummyHead = make_shared<ListNode<int>>();
    dummyHead->next = L;
	
    shared_ptr<ListNode<int>> sublistHead = dummyHead;

    int i = 0;
	while(i < start)
	{
		sublistHead = sublistHead->next;
		i++;
	}

	auto sublistIter = sublistHead->next;
	
	while(i < finish)
	{
		/*auto temp = sublistIter->next;
		sublistIter->next = temp->next;
		temp->next = */
		
		
		
		i++;
	}
	
  return dummyHead->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
