| Category | Function / Operator | Syntax Example | Description |
|----------|----------------------|----------------|-------------|
| String Length | `length()` / `size()` | `str.length()` | Returns the number of characters in the string. |
| Accessing Characters | Indexing (`[]`) | `str[2]` | Accesses the character at index 2 (no bounds checking). |
| | `at()` | `str.at(2)` | Accesses character at index 2 (with bounds checking). |
| Appending / Concatenation | `+` operator | `str1 + str2` | Concatenates two strings. |
| | `append()` | `str.append(other)` | Appends another string to the end. |
| String Comparison | `==` operator | `str1 == str2` | Compares two strings for equality. |
| | `compare()` | `str.compare(other)` | Returns integer result of lexicographical comparison. |
| Substrings | `substr()` | `str.substr(pos, len)` | Extracts substring starting at `pos` of length `len`. |
| Searching | `find()` | `str.find("abc")` | Returns index of first occurrence of substring `"abc"`. |
| Modifying Strings | `replace()` | `str.replace(pos, len, "new")` | Replaces part of the string. |
| | `insert()` | `str.insert(pos, "abc")` | Inserts a substring at position `pos`. |
| | `erase()` | `str.erase(pos, len)` | Removes `len` characters starting at `pos`. |
| Conversion | `c_str()` | `str.c_str()` | Returns a C-style null-terminated string (`const char*`). |

