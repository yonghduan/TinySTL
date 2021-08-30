//
// Created by Administrator on 2021/8/24.
//

#ifndef TINYSTL_ITERATOR_H
#define TINYSTL_ITERATOR_H

namespace stl{
template<typename T>
class Iterator{
public:
    //can achieve iterator type through this
    typedef typename T::iterator_category iterator_category;
};
}
#endif //TINYSTL_ITERATOR_H
