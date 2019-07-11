#include "lib.h"

int main(int argc, char* argv[]){
 auto vector_ip    = vector_to_ip(read_from_stream());
 using vector_type = decltype(vector_ip);
 vector_type vector_ip_filter;

 //Sorting addresses
 std::sort(vector_ip.begin(),vector_ip.end(),
            [](auto lhv,auto rhv) {
                 using tuple_type  = decltype(lhv);
                 return compare_tuple<tuple_type,std::tuple_size<tuple_type>::value-1,std::tuple_size<tuple_type>::value-1>(lhv,rhv,false);
                });
 print_vector(vector_ip);
 

 //Printing addresses starting from 1
 std::copy_if(vector_ip.begin(),vector_ip.end(),std::insert_iterator<vector_type>(vector_ip_filter,vector_ip_filter.begin()),
             [](auto ip){
                 if(std::get<0>(ip)==1) return true;
                 return false;
             });
 print_vector(vector_ip_filter);          

 //Printing addresses starting from 46.70
 vector_ip_filter.clear();
 std::copy_if(vector_ip.begin(),vector_ip.end(),std::insert_iterator<vector_type>(vector_ip_filter,vector_ip_filter.begin()),
             [](auto ip){
                 if(std::get<0>(ip)==46) 
                 if(std::get<1>(ip)==70) return true;
                 return false;
             });
 print_vector(vector_ip_filter);  

 //Printing any of byte equal 46
 vector_ip_filter.clear();
 std::copy_if(vector_ip.begin(),vector_ip.end(),std::insert_iterator<vector_type>(vector_ip_filter,vector_ip_filter.begin()),
             [](auto ip){
                 if(std::get<0>(ip)==46) return true;
                 if(std::get<1>(ip)==46) return true;
                 if(std::get<2>(ip)==46) return true;
                 if(std::get<3>(ip)==46) return true;
                 return false;
             });
 print_vector(vector_ip_filter);  

 UNUSED(argc);
 UNUSED(argv);
 return 0;
}