//
// Created by Administrator on 2021/8/23.
//

#ifndef TINYSTL_NEW_ALLOC_H
#define TINYSTL_NEW_ALLOC_H
#include<cstddef>
#include<new>
#include<iostream>
#include<cstdlib>
#include "../iterator.h"
#include "iterator_traits.h"
#include "type_traits.h"
namespace stl{
template<typename T>
class NewAlloc{
public:
    static T * Allocate();
    static T * Allocate(const size_t need_bytes);
    static void Deallocate(T * ptr_temp);
    static void Deallocate(T * * ptr_temp);
};
//NewAlloc class function
template<typename T>
T * NewAlloc<T>::Allocate(){
    std::set_new_handler(nullptr);
    T * ptr_temp =static_cast<T *>(::operator new(sizeof(T))) ;
    if(ptr_temp != nullptr)
        return ptr_temp;
    std::cerr << "memory allocation failed!\n";
    exit(1);
}

template<typename T>
T * NewAlloc<T>::Allocate(const size_t need_bytes) {
    std::set_new_handler(nullptr);
    T * ptr_temp = static_cast<T *>(::operator new(need_bytes));
    if(ptr_temp != nullptr)
        return ptr_temp;
    std::cerr << "memory allocation failed!\n";
    exit(1);
}

template<typename T>
void NewAlloc<T>::Deallocate(T * ptr_temp) {
    //std::cout << "NewAlloc::Deallocate()\n";
    ::operator delete(ptr_temp);
}

template<typename T>
void NewAlloc<T>::Deallocate(T **ptr_temp) {
    ::operator delete (ptr_temp);
}
//construct function and destroy function
template<typename T>
void Construct(T * ptr,const T & value){
    new(ptr) T(value);
}

template<typename Iterator>
inline void DestroyByType(const Iterator & iter,NeedDestroyType){
    typedef typename IteratorTraits<Iterator>::value_type value_type;
    (&*iter) -> ~value_tyep();
}

template<typename Iterator>
inline void DestroyByType(const Iterator &,NoDestroyType){}

template<typename Iterator>
void Destroy(const Iterator & iter){
    typedef typename IteratorTraits<Iterator>::value_type value_type;
    typedef typename TypeTraits<value_type>::has_trivial_destructor trivial_destructor;
    DestroyByType(iter,trivial_destructor());
}

template<typename Iterator>
void DestroyByType(const Iterator & iter_start,const Iterator & iter_end,struct NoDestroyType){
    //std::cout << "DestroyByType().NoDestroyType\n";
}

template<typename T>
inline void DestroyObject(T * ptr){
    ptr -> ~T();
}

template<typename Iterator>
void DestroyByType(const Iterator & iter_start,const Iterator & iter_end,struct NeedDestroyType){
    std::cout << "DestroyByType().NeedDestroyType.\n";

    typedef typename IteratorTraits<Iterator>::value_type value_type;
    for(Iterator iter_temp = iter_start;iter_temp != iter_end;++ iter_temp ){
        //std::cout << "executing ~string()\n";
        DestroyObject(&*iter_temp);
        //std::cout << "finish ~string()\n";
    }


}

template<typename Iterator>
void Destroy(const Iterator & iter_start,const Iterator & iter_end){
    //std::cout << "Destroy()\n";
    typedef typename IteratorTraits<Iterator>::value_type value_type;
    typedef typename TypeTraits<value_type>::has_trivial_destructor trivial_destructor;
    DestroyByType(iter_start,iter_end,trivial_destructor());
}

}
#endif //TINYSTL_NEW_ALLOC_H
