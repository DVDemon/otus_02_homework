#include "lib.h"



std::vector<std::string> read_from_stream(){
    std::istream_iterator<std::string> eos;
    std::istream_iterator<std::string> iit(std::cin);
    std::vector<std::string> result;
    std::insert_iterator<std::vector<std::string>> insert_it(result,result.begin());

    std::copy(iit,eos,insert_it);

    return result;
}

std::ostream& operator<<(std::ostream &lhv,ip_type rhv){
    lhv << std::get<0>(rhv) << "."<< std::get<1>(rhv) << "."<< std::get<2>(rhv) << "."<< std::get<3>(rhv);
    return lhv;
}

ip_type to_ip(std::string str){
    size_t values[]   {0,0,0,0};
    size_t index    {0};

    for(size_t i=0;i<str.size();i++){
        if((str[i]>='0')&&(str[i]<='9')){
            values[index]=values[index]*10+(str[i]-'0');
        } else
        if(str[i]=='.'){
            index++;
        }
    }

    return ip_type(values[0],values[1],values[2],values[3]);
}

std::vector<ip_type> vector_to_ip(std::vector<std::string> source){

    std::vector<ip_type> result;
    std::insert_iterator<std::vector<ip_type>> insert_it(result,result.begin());
    std::transform(source.begin(),
                          source.end(),
                          insert_it,
                          [](std::string str){
                              return to_ip(str);
                          }
      );
    return result;
}