# Sway Language - Quick Reference Card

## Variables

```sway
let x: Int = 10           // Immutable integer
let y = 20                // Type inference
var name: String = "Hi"   // Mutable variable
var x: Int                // Uninitialized (needs later assignment)
```

## Data Types

```
Int      - Integer (32-bit)
Float    - Floating point
String   - Text (const char*)
Bool     - Boolean (0/1)
Void     - No return value
Type?    - Optional type
```

## Functions

```sway
func add(a: Int, b: Int) -> Int {
    return a + b
}

func greet(name: String) -> String {
    return "Hello, " + name
}

func noReturn() -> Void {
    print(100)
}

// Call with named arguments
let sum = add(a: 5, b: 3)
let greeting = greet(name: "World")
```

## Control Flow

### If/Else
```sway
if x > 5 {
    print(1)
} else if x == 5 {
    print(0)
} else {
    print(-1)
}
```

### While Loop
```sway
var i: Int = 0
while i < 10 {
    print(i)
    i = i + 1
}
```

### For Loop (basic)
```sway
for item in list {
    print(item)
}
```

## Operators

### Arithmetic
```
+   Addition
-   Subtraction
*   Multiplication
/   Division
%   Modulo
```

### Comparison
```
==  Equal
!=  Not equal
<   Less than
>   Greater than
<=  Less or equal
>=  Greater or equal
```

### Logical
```
&&  AND
||  OR
!   NOT
```

### Assignment
```
=   Assign value
```

## Structures

### Struct
```sway
struct Person {
    name: String,
    age: Int
}
```

### Enum
```sway
enum Color {
    Red,
    Green,
    Blue
}
```

### Class
```sway
class Dog {
    name: String,
    age: Int
    
    func bark() -> Void {
        print(1)
    }
}
```

## Comments

```sway
// Single line comment

/* Multi-line
   comment */
```

## Built-in Functions

```sway
print(x)    // Print value
```

## Examples

### Example 1: Sum
```sway
func main() -> Void {
    var sum: Int = 0
    var i: Int = 1
    
    while i <= 5 {
        sum = sum + i
        i = i + 1
    }
    
    print(sum)  // 15
}
```

### Example 2: Max
```sway
func max(a: Int, b: Int) -> Int {
    if a > b {
        return a
    } else {
        return b
    }
}
```

### Example 3: Factorial
```sway
func fact(n: Int) -> Int {
    if n <= 1 {
        return 1
    }
    return n * fact(n: n - 1)
}
```

## Type Conversions

Sway → C Mapping:
```
Sway        C
Int     →   int
Float   →   float
String  →   const char*
Bool    →   int
Void    →   void
Type?   →   Type*
```

## Operator Precedence (High to Low)

```
1. Postfix (function calls, member access)
2. Unary (!, -)
3. Multiplicative (*, /, %)
4. Additive (+, -)
5. Comparison (<, >, <=, >=)
6. Equality (==, !=)
7. Logical AND (&&)
8. Logical OR (||)
9. Assignment (=)
```

## Common Patterns

### Pattern 1: Conditional Return
```sway
func isPositive(x: Int) -> Bool {
    if x > 0 {
        return 1
    } else {
        return 0
    }
}
```

### Pattern 2: Loop with Accumulator
```sway
func sum(n: Int) -> Int {
    var total: Int = 0
    var i: Int = 1
    while i <= n {
        total = total + i
        i = i + 1
    }
    return total
}
```

### Pattern 3: Recursion
```sway
func fib(n: Int) -> Int {
    if n <= 1 {
        return n
    }
    return fib(n: n - 1) + fib(n: n - 2)
}
```

### Pattern 4: Function Composition
```sway
func double(x: Int) -> Int {
    return x * 2
}

func addTen(x: Int) -> Int {
    return x + 10
}

func main() -> Void {
    let result = addTen(x: double(x: 5))
    print(result)  // 20
}
```

## CLI Commands

```bash
# Build (generate C code)
python3 sway.py build program.sway

# Run (build + compile + execute)
python3 sway.py run program.sway

# Compile C directly
python3 sway.py compile program.c -o program

# Show help
python3 sway.py --help
```

## Debugging Tips

1. **View Generated C Code**
   ```bash
   python3 sway.py build program.sway
   cat program.c
   ```

2. **Check Compilation Output**
   ```bash
   python3 sway.py compile program.c 2>&1 | head -20
   ```

3. **Trace Execution**
   - Add print statements
   - Check variable values
   - Verify control flow

## Common Errors

| Error | Cause | Fix |
|-------|-------|-----|
| "Expected type name" | Lowercase type | Use Int not int |
| "Unexpected character" | Invalid syntax | Check operators |
| "Expected expression" | Missing value | Add expression |
| "gcc not found" | gcc not installed | Install build-essential |

## Limitations (v0.1.0)

- ❌ No string interpolation \(expr)
- ❌ No array operations
- ❌ No struct initialization syntax
- ❌ Limited standard library
- ❌ No generics
- ❌ No error handling (try/catch)
- ❌ No closures

These will be added in future versions!

---

## Quick Start Template

```sway
// My first Sway program
func greet(name: String) -> String {
    return "Hello, " + name
}

func main() -> Void {
    let userName: String = "World"
    let message = greet(name: userName)
    print(message)
}
```

Compile and run:
```bash
python3 sway.py run program.sway
```

Output:
```
Hello, World
```

---

**Version**: 0.1.0  
**Last Updated**: April 2026
