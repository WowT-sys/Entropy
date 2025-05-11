#include <stdio.h>

// We dilute the .data section with zeros

template<unsigned int N, typename T, T value>
struct E {
    constexpr E() : array() {
        for (unsigned int i = 0; i < N; i++) {
            array[i] = (T)value;
        }
    }
    T array[N];
};

#pragma code_seg(".text")
__declspec(allocate(".text"))
constexpr auto e = E<2500, long long, 1>();

#pragma code_seg(".data")
__declspec(allocate(".data"))
constexpr auto e2 = E<2500, long long, 1>();

int main() {
    int total = 0;
    
    for (auto x : e.array)
        total += x;

    for (auto x : e2.array)
        total += x;

    return total;
}