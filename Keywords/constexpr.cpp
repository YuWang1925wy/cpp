// Notes (C++17):
// - constexpr *variables* must have compile-time initializers (and are implicitly const)
// - constexpr *functions* are allowed to be evaluated at compile time when called
//   with constant arguments in a constant-expression context; otherwise they run at runtime
// - C++11 restricted constexpr function bodies to a single return expr;
//   C++14+ allows local vars, loops, if/else, etc. (still with some limits)
// - In C++17, constexpr functions must return a literal type; `void` is not allowed
// - Reading a non-constexpr object during constant evaluation is ill-formed

#include <iostream>
#include <type_traits>

// 1) constexpr variable: must be a constant expression
constexpr double PI = 3.14159265358979323846;

// 2) constexpr function: may run at compile time OR runtime
//    (Pass small scalars by value—simpler rules for constant evaluation.)
constexpr double DegToRad(double deg) {
    return deg * (PI / 180.0);
}

// 3) constexpr function with loop (C++14+): iterative Fibonacci.
//    (Iterative to avoid compiler constexpr step limits seen with naive recursion.)
constexpr long long fib(int n) {
    long long a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        long long nxt = a + b;
        a = b;
        b = nxt;
    }
    return a;
}

// 4) "Interface" style: constexpr constructor + constexpr member.
struct Rectangle {
    int h, w;
    constexpr Rectangle(int h, int w) : h(h), w(w) {}
    constexpr int area() const { return h * w; }
};

// 5) if constexpr (C++17): compile-time branching in templates.
template <class T>
constexpr auto zero_if_integral_else_one() {
    if constexpr (std::is_integral_v<T>) {
        return T{0};    // this branch is compiled only for integral T
    } else {
        return T{1};    // this one only for non-integral T
    }
}

// 6) Non-constexpr function: callable from constexpr functions only at runtime,
//    not in a constant-expression context.
int runtime_only_square(int x) { return x * x; }

int main() {
    // --- Compile-time uses (prove with static_assert) ---
    constexpr double quarter_turn = DegToRad(90.0);
    static_assert(quarter_turn > 1.5707 && quarter_turn < 1.5709, "angle check");

    constexpr auto f30 = fib(30);
    static_assert(f30 == 832040, "fib(30) check");

    constexpr Rectangle r{10, 20};
    static_assert(r.area() == 200, "area check");

    // --- Runtime uses of the same constexpr functions ---
    double deg = 45.0;               // not a constant expression
    auto angle_rt = DegToRad(deg);   // evaluated at runtime (still fine)

    int n = 7;
    int rsq = runtime_only_square(n); // runtime OK
    // constexpr int bad = runtime_only_square(7); // ERROR in C++17: not a constant expression

    // --- if constexpr demo ---
    auto zi = zero_if_integral_else_one<int>();    // 0 (chosen at compile time)
    auto zd = zero_if_integral_else_one<double>(); // 1.0

    std::cout << "90 deg in rad (CT): " << quarter_turn << '\n';
    std::cout << "fib(30) (CT):       " << f30 << '\n';
    std::cout << "Rectangle area (CT): " << r.area() << '\n';
    std::cout << "45 deg in rad (RT): " << angle_rt << '\n';
    std::cout << "square(7) (RT):     " << rsq << '\n';
    std::cout << "zero_if_integral<int>():    " << zi << '\n';
    std::cout << "zero_if_integral<double>(): " << zd << '\n';
}

/*
Extras:

// C++20 adds consteval (must be evaluated at compile time) and constinit.
// Example (requires -std=c++20):
consteval int always_ct(int x) { return x + 1; }
constexpr int y = always_ct(41); // OK (compile time)

// In C++17, constexpr void f() is not allowed (void isn't a literal type for constexpr).
// In C++20, constexpr void is permitted for certain contexts, but it still can't be a constant expression.
*/
