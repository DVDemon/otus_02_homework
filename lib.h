#ifndef LIB
#define LIB

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

std::vector<std::string>    read_from_stream();
void                        print_vector(const std::vector<std::string> vec);
std::vector<std::tuple<int,int,int,int>> vector_to_ip(std::vector<std::string> source);

#endif