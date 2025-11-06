| Aspect | NRVO (Named Return Value Optimization) | RVO (Return Value Optimization) |
|---|---|---|
| What it is | Optimization when returning a named local object. | Optimization when returning a temporary/prvalue (unnamed) object. |
| Guarantee | Not guaranteed by the standard (though widely implemented by compilers). | From C++17, guaranteed copy elision when returning a prvalue of the function’s return type; before C++17 it was permitted but not guaranteed. |
| How it works | Instead of creating a local return object and then copying/moving it to the caller, the object is constructed directly in the caller’s storage, even though you wrote `T x; return x;`. | The returned prvalue is constructed directly in the caller’s storage; no local temporary is materialized and no copy/move constructor is invoked (e.g., `return T(...);`). |
| Typical form | `T f() { T x(...); return x; }` | `T f() { return T(...); }` |
