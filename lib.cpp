#include "lib.h"

#include <iterator>

std::vector<std::string> read_from_stream(){
    std::istream_iterator<std::string> eos;
    std::istream_iterator<std::string> iit(std::cin);
    std::vector<std::string> result;
    std::insert_iterator<std::vector<std::string>> insert_it(result,result.begin());

    std::copy(iit,eos,insert_it);

    return result;
}

void print_vector(const std::vector<std::string> vec){
  for(auto s:vec){
      std::cout << s << std::endl;
  }
}

std::vector<std::tuple<int,int,int,int>> vector_to_ip(std::vector<std::string> source){
    std::vector<std::tuple<int,int,int,int>>  result;

    for(auto str: source){
 //       std::tuple<int,int,int,int> tpl;
 //       int  index;
    }

    return result;
}