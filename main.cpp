#include "lib.h"

#define UNUSED(variable)  (void)variable

int main(int argc, char* argv[]){

 auto vector = read_from_stream();
 print_vector(vector);
 
 UNUSED(argc);
 UNUSED(argv);
 return 0;
}