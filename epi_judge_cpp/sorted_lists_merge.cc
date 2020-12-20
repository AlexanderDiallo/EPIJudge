#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  // TODO - you fill in here.

    auto dummyHead = make_shared<ListNode<int>>();

	auto currentNode = dummyHead;
	
	while(true)
	{
		if(!L1)
		{
			currentNode->next = L2;
			break;
		}
		else if (!L2)
		{
			currentNode->next = L1;
			break;
		}

		if(L1->data < L2->data)
		{
			currentNode->next = L1;
			L1 = L1->next;
			currentNode = currentNode->next;
		}
		else
		{
			currentNode->next = L2;
			L2 = L2->next;
			currentNode = currentNode->next;
		}
	}
	
  return dummyHead->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}
