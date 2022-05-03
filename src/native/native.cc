#include <unordered_map>
#include <vector>
#include "symbols.hh"
#include "vm.hh"

#include "native/array.hh"


#define vecT(args...) std::vector<DataType>{args}
#define vecI(args...) std::vector<i64>{args}

#define INT DataType::INT
#define INTARR DataType::INTARR

#define func(fields...) {fields}

#define vm_nat(fun) vm.add_native_fun(fun)


void add_native_functions(std::unordered_map<string, FuncEntry> &natives)
{
    #define add_native(name, entry) do { \
        natives[name] = entry; \
    } while(0)


    add_native("Array1DLen", func(INT, 0, vm_nat(Array_1D_Len), vecT(INTARR), vecI(1)));
    

    #undef add_native
}