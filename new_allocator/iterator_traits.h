//
// Created by Administrator on 2021/8/24.
//

#ifndef TINYSTL_ITERATOR_TRAITS_H
#define TINYSTL_ITERATOR_TRAITS_H
namespace stl{
template<typename Iterator>
class IteratorTraits{
public:
    typedef typename Iterator::value_type value_type;
};
}
#endif //TINYSTL_ITERATOR_TRAITS_H
