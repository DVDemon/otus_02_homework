#ifndef LIB
#define LIB

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

#define UNUSED(variable)  (void)variable
using ip_type = std::tuple<size_t,size_t,size_t,size_t>;

std::ostream& operator<<(std::ostream &lhv,ip_type rhv);

template <class T> 
void print_vector(const std::vector<T> vec){
  for(auto s:vec){
      std::cout << s << std::endl;
  }
};

template <class T,size_t index,size_t size> constexpr bool compare_tuple(T& lhv,T& rhv,bool less){
    if (std::get<size-index>(lhv) == std::get<size-index>(rhv)) {
        if constexpr (index>0) return compare_tuple<T,index-1,size>(lhv,rhv,less);
                               return false;
    }

   if(less) return (std::get<size-index>(lhv) < std::get<size-index>(rhv));
     else   return (std::get<size-index>(lhv) > std::get<size-index>(rhv));
};

std::vector<std::string>    read_from_stream();
std::vector<ip_type>        vector_to_ip(std::vector<std::string> source);
ip_type                     to_ip(std::string str);


#endif