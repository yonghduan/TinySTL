#include <iostream>
#include "deque/deque.h"
#include "list/slist.h"
#include "iterator.h"

using std::cout;
using std::endl;

int main() {
    std::cout << "Hello, World!" << std::endl;
    stl::Deque<std::string> deque(20,"abc");
    std::cout << std::endl;
    std::cout << deque[12] << endl;
    deque[16] = "zhgjjgdkgjkdgjgik";
    cout << deque[16] <<endl;
    deque.PushBack("dyh");
    deque.PushBack("dyh");
    stl::IteratorDeque<std::string> iter_end = deque.End();
    for(stl::IteratorDeque<std::string> iter = deque.Begin();iter != iter_end;++ iter)
        cout << *iter << "  ";

    cout << "\n=======================================\n";
    cout << "========================================\n";

    stl::Deque<char> deque1(20,'c');
    typedef stl::Iterator<stl::Deque<char>>::iterator_category iterator_category;
    for(iterator_category iter2 = deque1.Begin();iter2 != deque1.End();++ iter2 ){
        cout << *iter2 << " ";
    }
    return 0;
}
