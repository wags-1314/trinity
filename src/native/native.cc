#include <unordered_map>
#include <vector>
#include "symbols.hh"
#include "vm.hh"

#include "native/array.hh"
#include "native/io.hh"


#define vecT(args...) std::vector<DataType>{args}
#define vecI(args...) std::vector<i64>{args}

#define NIL DataType::NIL
#define INT DataType::INT
#define INTARR DataType::INTARR
#define STR DataType::STR
#define STRARR DataType::STRARR

#define func(fields...) {fields}

#define vm_nat(fun) vm.add_native_fun(fun)


void add_native_functions(std::unordered_map<string, FuncEntry> &natives)
{
    #define add_native(name, entry) do { \
        natives[name] = entry; \
    } while(0)


    add_native("prints", func(NIL, 0, vm_nat(nat_prints), vecT(STR)));
    add_native("printi", func(NIL, 0, vm_nat(nat_printi), vecT(INT)));
    add_native("cls", func(NIL, 0, vm_nat(nat_cls)));
    
    add_native("up_pressed?", func(INT, 0, vm_nat(nat_up_pressed)));
    add_native("down_pressed?", func(INT, 0, vm_nat(nat_down_pressed)));
    add_native("left_pressed?", func(INT, 0, vm_nat(nat_left_pressed)));
    add_native("right_pressed?", func(INT, 0, vm_nat(nat_right_pressed)));

    add_native("draw_at", func(NIL, 0, vm_nat(nat_draw_at), vecT(INT, INT, INT)));
    add_native("grid_at", func(INT, 0, vm_nat(nat_grid_at), vecT(INT, INT)));

    add_native("exit", func(NIL, 0, vm_nat(nat_exit)));

    add_native("Array1DLen", func(INT, 0, vm_nat(Array_1D_Len), vecT(INTARR), vecI(1)));
    

    #undef add_native
}