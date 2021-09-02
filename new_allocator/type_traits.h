//
// Created by Administrator on 2021/8/24.
//

#ifndef TINYSTL_TYPE_TRAITS_H
#define TINYSTL_TYPE_TRAITS_H
namespace stl{
struct NeedDestroyType{};
struct NoDestroyType{};

template<typename T>
class TypeTraits{
public:
    typedef NeedDestroyType has_trivial_destructor;
};

template<>
class TypeTraits<int>{
public:
    typedef NoDestroyType has_trivial_destructor;
};

template<>
class TypeTraits<std::string>{
public:
    typedef NeedDestroyType has_trivial_destructor;
};

template<>
class TypeTraits<char>{
public :
    typedef NoDestroyType has_trivial_destructor;
};

template<>
class TypeTraits<double>{
public:
    typedef NoDestroyType has_trivial_destructor;
};

}
#endif //TINYSTL_TYPE_TRAITS_H
