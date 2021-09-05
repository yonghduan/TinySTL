//
// Created by Administrator on 2021/9/2.
//

#ifndef TINYSTL_SLIST_H
#define TINYSTL_SLIST_H

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
    SlistNodeBase slist_ptr;
public:

};

template<typename T>
class Slist{
public :
    typedef T value_type;
private:
    SlistNode<T> head;  //it is a true things

};


#endif //TINYSTL_SLIST_H
