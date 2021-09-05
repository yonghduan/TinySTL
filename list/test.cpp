//
// Created by Administrator on 2021/8/23.
//
#include "list.h"
#include "iterator.h"
#include<string>
int main(){
    using namespace stl;
    List<std::string> list;
    list.PushFront("i");
    list.PushFront("am");
    list.PushFront("a");
    list.PushFront("cool");
    list.PushFront("boy");
    typedef Iterator<List<std::string>>::iterator_category iterator_category;
    for(iterator_category iter_temp = list.Begin();iter_temp <= list.End();iter_temp ++)
        std::cout << *iter_temp <<" ";
    std::cout << "\n=================================\n";
    iterator_category iter = list.Begin();
    std::cout << "operator->: result is " << iter -> data;
    std::cout << "\n=================================\n";
    std::cout << list[3];
    list[3] = "you are so smart";
    std::cout << std::endl << list[3];
    std::cout << "\n===================================\n";
    try {
        list[8] =  4;
    }
    catch(const std::string & str){
        std::cout << str << std::endl;
        exit(1);
    }
    return 0;
}
