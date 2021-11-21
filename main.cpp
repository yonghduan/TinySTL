#include <iostream>
#include "deque/deque.h"
#include "list/slist.h"
#include "iterator.h"

using std::cout;
using std::endl;

int main() {
   Slist<std::string> slist;
   slist.pushFront("abc");
   slist.pushFront("abcd");
   slist.pushFront("abcde");
   stl::Iterator<Slist<std::string>>::iterator_category iter = slist.begin();
   cout << *iter << " ";
   iter ++;
   cout << *iter << " ";
   iter ++;
   cout << *iter;
    return 0;
}
