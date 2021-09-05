//
// Created by Administrator on 2021/9/2.
//

#ifndef TINYSTL_SLIST_H
#define TINYSTL_SLIST_H
#include "../new_allocator/new_alloc.h"
struct SlistNodeBase{
    struct SlistNodeBase * next;
};

template<typename T>
struct SlistNode : public SlistNodeBase{
    T data;
};

template<typename T>
class IteratorSlistBase{
private:
    SlistNodeBase * ptr;
public:
    IteratorSlistBase() : ptr(nullptr){}
    IteratorSlistBase(SlistNodeBase * ptr_temp) : ptr(ptr_temp){}
};

template<typename T>
class IteratorSlist{
public:
    typedef T value_type;
private:
    struct SlistNodeBase * ptr;
public:
    IteratorSlist() : ptr(nullptr){}
    IteratorSlist(struct SlistNodeBase * ptr_temp) : ptr(ptr_temp){}
    T & operator* () {return ((SlistNode<T> *)ptr) -> data;}
    IteratorSlist & operator++ (){ptr = ptr -> next;return *this;}  //return
    IteratorSlist operator++(int){IteratorSlist<T> iter_temp;++(*this);return iter_temp;}
    bool operator!=(const SlistNodeBase * ptr_temp){return ptr != ptr_temp;}
    SlistNodeBase * getPtr() const {return ptr;}
    bool operator!=(const IteratorSlist<T> & iter_list){return ptr != iter_list.getPtr();}
};

template<typename T,typename Alloc = stl::NewAlloc<T>>
class Slist{
public :
    typedef T value_type;
    typedef SlistNode<T> list_node;
    typedef SlistNodeBase list_node_base;
    typedef IteratorSlist<T> iterator_category;
private:
    SlistNode<T> head;  //it is a true things
public:
    //constructor and destructor
    Slist(){head.next = nullptr;}
    ~Slist();
    //functions
    IteratorSlist<T> begin(){return IteratorSlist<T>(head.next);}
    bool empty(){return head.next == nullptr;}
    void pushFront(const T & value);
    void popFront();
};
//functions implement
template<typename T,typename Alloc>
Slist<T,Alloc>::~Slist(){
    //destroy
    stl::Destroy(this -> begin(),iterator_category(nullptr));
    //deallocate
    list_node * ptr_free = (list_node *)head.next;
    while(ptr_free != nullptr){
        list_node * next_free = (list_node *)ptr_free -> next;
       ::operator delete (ptr_free);
        ptr_free = next_free;
    }

}
template<typename T,typename Alloc>
void Slist<T,Alloc>::pushFront(const T & value) {
    list_node * ptr_temp = static_cast<list_node *>(Alloc::Allocate(sizeof(list_node)));
    std::cout << "allocation is succsssful.\n";
    ptr_temp -> data = value;
    ptr_temp -> next = head.next;
    head.next = (list_node_base *)ptr_temp;
}

#endif //TINYSTL_SLIST_H
