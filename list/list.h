//
// Created by Administrator on 2021/8/23.
//

#ifndef TINYSTL_LIST_H
#define TINYSTL_LIST_H
#include "new_alloc.h"
#include<cstddef>
#include<iostream>
namespace stl{
//list node
template<typename T>
struct ListNode{
    typedef struct ListNode<T> * list_node_ptr;
    T data;
    list_node_ptr pre_ptr;
    list_node_ptr next_ptr;
};
//list iterator
template<typename T>
class IteratorList{
public:
    typedef T value_type;
    typedef struct ListNode<T> *  list_node_ptr;
private:
    list_node_ptr ptr;
public:
    IteratorList(list_node_ptr node_ptr):ptr(node_ptr){};
    list_node_ptr GetPtr() const{return ptr;}
    //operator reload
    T & operator* () const{return ptr -> data;}
    IteratorList<T> & operator++ () {ptr = ptr -> next_ptr;return *this;}
    IteratorList<T> & operator-- () {ptr = ptr -> pre_ptr;return *this;}
    IteratorList<T> operator++ (int) {
        //std::cout << "++ operator.\n";
        IteratorList<T> iter = (*this);++ (*this) ;return iter;
    }
    IteratorList<T> operator-- (int){IteratorList<T> iter = (*this);(*this) --;return iter;}
    bool operator<= (const IteratorList<T> & iter) const;
    bool operator!= (const IteratorList<T> & iter) const{return ptr != iter.ptr;}
    bool operator== (const IteratorList<T> & iter) const{return ptr == iter.ptr;}
    list_node_ptr operator-> () const{return ptr;}
};

template<typename T>
bool IteratorList<T>::operator<= (const IteratorList<T> & iter) const{

    if((ptr == nullptr) || (ptr == iter.ptr -> next_ptr)){
        //std::cout << "<= operator false.\n";
        return false;
    }
    else{
        //std::cout << "<= operator true.\n";
        return true;
    }

}
//List Container
template<typename T,typename Alloc = NewAlloc<struct ListNode<T>>>
class List{
public:
    typedef T value_type;
    typedef value_type * pointer;
    typedef value_type & reference;
    typedef ptrdiff_t difference;
    typedef size_t size_type;
    typedef  struct ListNode<T> * list_node_ptr;
    typedef IteratorList<T> iterator_category;
    enum {unit_bytes = sizeof(T)};
    //some container arguments,which should be accessed by deprived class ,but not other class
protected:
    list_node_ptr start;
    list_node_ptr finish;
    size_type size;
    void Deallocate(const IteratorList<T> & iter_start,const IteratorList<T> & iter_end);
public:
    //public functions
    IteratorList<T> Begin(){return IteratorList<T>(start);}
    IteratorList<T> End(){return IteratorList<T>(finish);}
    size_type Size(){return size;}
    IteratorList<T> PushFront(const T  & temp);
    T & operator[] (unsigned int index);
    //constructor
    List():start(nullptr),finish(nullptr),size(0){std::cout << "constructor()\n";}
    //destructor
    ~List(){std::cout << "destructor()\n";Destroy(Begin(),End());Deallocate(start,finish);}



};
//protected functions
template<typename T,typename Alloc>
void List<T,Alloc>::Deallocate(const IteratorList<T> & iter_start,const IteratorList<T> & iter_end){
    std::cout << "Deallocate()\n";
    for(IteratorList<T> iter_temp = iter_start;iter_temp <= iter_end;iter_temp ++)
        Alloc::Deallocate(iter_temp.GetPtr());

}
//public functions implement
template<typename T,typename Alloc>
T & List<T,Alloc>::operator[] (unsigned int index){
    if((index < 0) || (index >= size)){
        std::string str = "index is out of size.";
        throw(str);
    }
    IteratorList<T> iter_list = start;
    for(unsigned int i = 0;i < index;i ++){
        iter_list ++;
    }
    return *iter_list;
}

template<typename T,typename Alloc>
IteratorList<T> List<T,Alloc>::PushFront(const T &temp) {
    //std::cout << "PushFront()\n";
    struct ListNode<T>  * list_node_ptr = Alloc::Allocate();
    list_node_ptr -> data = temp;
    size ++;
    if(start != nullptr){
        start -> pre_ptr = list_node_ptr;
        list_node_ptr -> next_ptr = start;
        start = list_node_ptr;
        start -> pre_ptr = nullptr;
    }
    else{
        //the list is empty
        list_node_ptr -> pre_ptr = nullptr;
        list_node_ptr -> next_ptr = nullptr;
        start = finish = list_node_ptr;
    }

    return start;
}

}
#endif //TINYSTL_LIST_H
