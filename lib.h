#ifndef LIB
#define LIB

#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <iterator>
#include <algorithm>

#define UNUSED(variable)  (void)variable
using ip_type = std::tuple<size_t,size_t,size_t,size_t>;

std::ostream& operator<<(std::ostream &lhv,ip_type rhv);

template <class T> 
void print_vector(const std::vector<T> vec){
  for(auto s:vec){
      std::cout << s << std::endl;
  }
}

/* 
// comapre with if constexp - not working in travis
template <class T,size_t index,size_t size> constexpr bool compare_tuple(T& lhv,T& rhv,bool less){
    if (std::get<size-index>(lhv) == std::get<size-index>(rhv)) {
        if constexpr (index>0) return compare_tuple<T,index-1,size>(lhv,rhv,less);
                               return false;
    }

   if(less) return (std::get<size-index>(lhv) < std::get<size-index>(rhv));
     else   return (std::get<size-index>(lhv) > std::get<size-index>(rhv));
}
*/

// compare tuple with SFINAE :-(

template <class T,size_t index,size_t size> constexpr 
 typename std::enable_if<(index==0),bool>::type compare_tuple_sf(T& lhv,T& rhv,bool less){
   if(less) return (std::get<size-index>(lhv) < std::get<size-index>(rhv));
     else   return (std::get<size-index>(lhv) > std::get<size-index>(rhv));
}

template <class T,size_t index,size_t size> constexpr 
 typename std::enable_if<(index>0),bool>::type compare_tuple_sf(T& lhv,T& rhv,bool less){
    if (std::get<size-index>(lhv) == std::get<size-index>(rhv)) {
        return compare_tuple_sf<T,index-1,size>(lhv,rhv,less);
    }

   if(less) return (std::get<size-index>(lhv) < std::get<size-index>(rhv));
     else   return (std::get<size-index>(lhv) > std::get<size-index>(rhv));
}



// helper functions

std::vector<std::string>    read_from_stream();
std::vector<ip_type>        vector_to_ip(std::vector<std::string> source);
ip_type                     to_ip(std::string str);


#endif