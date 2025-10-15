// Build : g++ -std=c++17 constexpr2.cpp

#include <chrono>
#include <cstdint>
#include <iostream>

// ---------- constexpr version (compile-time) ----------
constexpr long long fib_ct(int n) {
    long long a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        long long nxt = a + b;
        a = b; b = nxt;
    }
    return a;
}
constexpr long long CT_VAL = fib_ct(30);  // computed at compile time

// ---------- runtime version (prevent inlining/const-folding) ----------
#if defined(__GNUC__) || defined(__clang__)
__attribute__((noinline))
#endif
long long fib_rt(int n) {                  // same algorithm, but runtime
    long long a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        long long nxt = a + b;
        a = b; b = nxt;
    }
    return a;
}

int main() {
    using clock = std::chrono::high_resolution_clock;
    constexpr std::size_t ITERS = 5'000'000;  // bump up/down as your machine allows

    volatile long long sink = 0;  // prevents dead-code elimination

    // ---- Baseline: just use the compile-time constant in a loop ----
    auto t0 = clock::now();
    long long acc = 0;
    for (std::size_t i = 0; i < ITERS; ++i) {
        acc += CT_VAL;             // no fib work at runtime
    }
    sink = acc;                    // keep it observable
    auto t1 = clock::now();

    // ---- Runtime: actually compute fib(30) each iteration ----
    volatile int vn = 30;          // volatile blocks constant propagation
    acc = 0;
    auto t2 = clock::now();
    for (std::size_t i = 0; i < ITERS; ++i) {
        acc += fib_rt(vn);         // real work at runtime
    }
    sink ^= acc;
    auto t3 = clock::now();

    auto dt_const  = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    auto dt_runtime= std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count();

    std::cout << "Add constexpr constant (CT) : " << dt_const   << " us\n";
    std::cout << "Compute fib at runtime (RT) : " << dt_runtime << " us\n";
    std::cout << "RT / CT speed ratio         : " << (double)dt_runtime / (dt_const ? dt_const : 1) << '\n';
    std::cerr << ""; // keep 'sink' live; prevents over-aggressive DCE
    return (int)sink; // tiny use of 'sink'
}
