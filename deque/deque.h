//
// Created by Administrator on 2021/8/29.
//

#ifndef TINYSTL_DEQUE_H
#define TINYSTL_DEQUE_H
#include "../new_allocator/new_alloc.h"

namespace stl{
template<typename T>
class IteratorDeque{
public:
    typedef T value_type;
private:
   T * current;
   T * * map_pointer;
   unsigned int map_index;
   unsigned int buffer_index;
public:
    IteratorDeque(T * current_temp,T * * map_ptr_temp);
    T & operator* (){return *current;}
    IteratorDeque<T> & operator++();
    bool operator!= (const IteratorDeque<T> & iter){return current != iter.current;}
};

template<typename T>
IteratorDeque<T> & IteratorDeque<T>::operator++() {
    //std::cout << "map_index= " << map_index << " buffer_index= " << buffer_index << std::endl;
    if(buffer_index != 7){
        buffer_index ++;
        current ++;
        return *this;
    }
    //index = 7
    //std::cout << "map_pointer[" << map_index << "]" << "= " << map_pointer[map_index] << std::endl;
    map_index += 1;
    buffer_index = 0;
    current = map_pointer[map_index];
    //std::cout << "map_pointer[" << map_index << "]" << "= " << map_pointer[map_index];
    return *this;
}

template<typename T>
IteratorDeque<T>::IteratorDeque(T *current_temp,T **map_ptr_temp) {
    current = current_temp;
    map_pointer = map_ptr_temp;
    for(unsigned int i = 0;i < 512;i ++){
        if(current_temp >= map_pointer[i] && current_temp <= (map_pointer[i] + 7)){
            map_index = i;
            break;
        }
    }
    //std::cout << map_index << "\n";
    for(unsigned j = 0;j < 8;j ++){
        if(current_temp == (map_pointer[map_index] + j)){
            buffer_index = j;
            break;
        }
    }

}

template<typename T,typename Alloc = NewAlloc<T>>
class Deque{
public:
    typedef T value_type;
    typedef T * pointer;
    typedef IteratorDeque<T> iterator_category;
private:
    void InitialDeque(const size_t & element_number,const T & initial_value,const size_t & index);
protected:
    pointer start;
    pointer finish;
    pointer * map_pointer;
    size_t map_size;
    size_t map_start_index;
    size_t map_finish_index;
    size_t size;
public:
    //constructor and destructor
    Deque(){map_pointer = nullptr;start = finish = nullptr;map_size = 0;map_start_index = 0;size = 0;}
    Deque(const size_t & element_number,const T & initial_value);
    ~Deque();
    //public functions
    T GetStart(){return *start;}
    T GEtEnd(){return *finish;}
    T & operator[] (unsigned int i);
    IteratorDeque<T> Begin(){return IteratorDeque<T>(start,map_pointer);}
    IteratorDeque<T> End(){return IteratorDeque<T>(finish,map_pointer);}
    bool PushBack(const T & value);
    bool PushFront(const T & value);
};

template<typename T,typename Alloc>
bool Deque<T,Alloc>::PushBack(const T &value) {
    if(finish != (map_pointer[map_finish_index] + 7)){
        //no reach border
        *(++ finish) = value;
        return true;
    }
    //reach border
    map_finish_index ++;
    map_size ++;
    map_pointer[map_finish_index] = Alloc::Allocate(8 * sizeof(T));
    finish = map_pointer[map_finish_index];
    *finish = value;
    return true;
}

template<typename T,typename Alloc>
Deque<T,Alloc>::~Deque(){
    Destroy(this -> Begin(),this -> End());
    for(unsigned int i = 0;i < map_size;i ++){
        Alloc::Deallocate(map_pointer[map_start_index + i]);
    }
    Alloc::Deallocate(map_pointer);
}

template<typename T,typename Alloc>
T & Deque<T,Alloc>::operator[](unsigned int i) {
    size_t map_index = i / 8;
    unsigned short buffer_index = i % 8;
    return *(map_pointer[map_start_index + map_index]+buffer_index);
}

template<typename T,typename Alloc>
void Deque<T,Alloc>::InitialDeque(const size_t &element_number, const T &initial_value,const size_t &
index){
    size_t need_buffer_num = element_number / 8 + 1;
    size_t break_flag = element_number % 8;
    int j;
    for(int i = 0;i < need_buffer_num; i ++){
        for(j = 0;j < 8;j ++){
            if(i == (need_buffer_num - 1) && j == break_flag)
                break;
            Construct(map_pointer[index + i]+j,initial_value);
        }
    }
    finish = map_pointer[index + need_buffer_num - 1]+break_flag - 1;
}

//constructor
template<typename T,typename Alloc>
Deque<T,Alloc>::Deque(const size_t & element_number,const T & initial_value){
    //initially map has 512 a pointer that points to the buffer
    size = element_number;
    map_pointer = new pointer[512];
    for(int i = 0;i < 512; i ++)
        map_pointer[i] = nullptr;
    //by default each buffer can have 8 elements
    size_t need_buffer_num = element_number / 8 + 1;
    map_size = need_buffer_num;
    size_t initial_map_index = 255 - (map_size / 2);
    for(int i = 0;i < need_buffer_num;i ++)
        map_pointer[initial_map_index + i] = Alloc::Allocate(8 * sizeof(T));
    for(int i = 0;i < need_buffer_num;i ++)
        std::cout << initial_map_index+i << ":" <<
        static_cast<void *>(( map_pointer[initial_map_index + i])) << " ";
    start = map_pointer[initial_map_index];
    map_start_index = initial_map_index;
    map_finish_index = initial_map_index + need_buffer_num - 1;
    InitialDeque(element_number,initial_value,initial_map_index);

}
}
#endif //TINYSTL_DEQUE_H
