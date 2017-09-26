# optional
Simple handmade std::optional implementation. It covers the regular functionality of std::optional from c++17 but without exceptions so it can be use in gamedev. It throws an assert if the value was never set but it is tried to be read.

# How to use it

``` cpp
#include <optional.h>

struct vec2 {
    int x;
    int y;
};

enum class MemoryChip : int {
       MBC1 = 0,
       MBC2
};

int main(int argc, char**argv) {
    // primitive types
    optional<float> scalar(3.5f);
    int max = scalar.value() * 2; 

    optional<int> currency;
    int totalCurrency = currency.value() * 2;  // -- Error (assert)
    
    // enums
    optional<MemoryChip> chip;
    chip = MemoryChip::MBC1;
    if (chip.value() == MemoryChip::MBC1) {
        // Do stuff
    }
    
    // structs
    optional<vec2> v;
    v = {12, 12};
    
    int distance = v->x - v->y;
}
```
