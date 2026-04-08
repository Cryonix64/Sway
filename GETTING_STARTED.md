# Sway Language - Getting Started Guide

## Installation

### 1. Check Prerequisites
```bash
# Check Python version (need 3.7+)
python3 --version

# Check gcc is installed
gcc --version

# If gcc not installed, install it:
# Ubuntu/Debian:
sudo apt-get install build-essential

# macOS:
brew install gcc

# Fedora:
sudo dnf install gcc
```

### 2. Navigate to Sway Directory
```bash
cd /home/dozirod/Documents/sway
```

## Basic Usage

### Command 1: Build (Generate C Code)
Generate C code from Sway program:
```bash
python3 sway.py build examples/simple.sway
```

**Output:**
- Creates `examples/simple.c` with generated C code
- Prints the C code to console

**Use when:** You want to see what C code is generated

---

### Command 2: Run (Build + Compile + Execute)
Compile and run a Sway program in one step:
```bash
python3 sway.py run examples/arithmetic.sway
```

**What it does:**
1. Tokenizes the source
2. Parses to AST
3. Generates C code
4. Compiles with gcc
5. Runs the executable

**Output:** Program output directly in console

**Use when:** You want to quickly test a program

---

### Command 3: Compile (C to Executable)
Compile generated C code:
```bash
python3 sway.py compile examples/simple.c -o simple
./simple
```

**Use when:** You want to manually manage the compilation

---

## Example Walkthrough

### Example 1: Simple Function Call

**File:** `examples/simple.sway`
```sway
func printNumber(n: Int) -> Void {
    print(n)
}

func main() -> Void {
    let num: Int = 42
    printNumber(n: num)
}
```

**Run it:**
```bash
python3 sway.py run examples/simple.sway
```

**Output:**
```
42
```

**What happens:**
1. `let num: Int = 42` creates an immutable integer variable=
2. `printNumber(n: num)` calls the function with named argument `n`
3. `print(num)` outputs the value using printf

---

### Example 2: Arithmetic and Variables

**File:** `examples/arithmetic.sway`
```sway
func main() -> Void {
    let x: Int = 10
    let y: Int = 20
    let sum = x + y
    
    print(sum)
    
    var counter: Int = 0
    counter = counter + 1
    
    print(counter)
}
```

**Run it:**
```bash
python3 sway.py run examples/arithmetic.sway
```

**Output:**
```
30
1
```

**Key differences:**
- `let sum` - Immutable variable with type inference
- `var counter` - Mutable variable (can be reassigned)
- `counter = counter + 1` - Assignment expression

---

### Example 3: Conditional Logic

**File:** `examples/conditions.sway`
```sway
func max(a: Int, b: Int) -> Int {
    if a > b {
        return a
    } else {
        return b
    }
}

func main() -> Void {
    let result = max(a: 5, b: 10)
    print(result)
}
```

**Run it:**
```bash
python3 sway.py run examples/conditions.sway
```

**Output:**
```
10
```

**Features used:**
- Named function parameters
- If/else statements
- Return values
- Type annotations

---

### Example 4: Recursion

**File:** `examples/factorial.sway`
```sway
func factorial(n: Int) -> Int {
    if n <= 1 {
        return 1
    } else {
        return n * factorial(n: n - 1)
    }
}

func main() -> Void {
    let result = factorial(n: 5)
    print(result)
}
```

**Run it:**
```bash
python3 sway.py run examples/factorial.sway
```

**Output:**
```
120
```

**Calculation:** 5! = 5 × 4 × 3 × 2 × 1 = 120

---

### Example 5: Loops

**File:** `examples/loops.sway`
```sway
func main() -> Void {
    var i: Int = 0
    
    while i < 5 {
        print(i)
        i = i + 1
    }
}
```

**Run it:**
```bash
python3 sway.py run examples/loops.sway
```

**Output:**
```
0
1
2
3
4
```

---

## Understanding Generated C Code

### View Generated Code:
```bash
python3 sway.py build examples/simple.sway
cat examples/simple.c
```

### Generated C for Simple Example:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printNumber(int n);
void main(void);

void printNumber(int n) {
    printf("%d\n", n);
}

void main(void) {
    int num = 42;
    printNumber(num);
}
```

### Mapping Sway → C:
```
Sway                          C
let num: Int = 42      →      int num = 42;
func name() -> Void    →      void name(void) { ... }
print(x)               →      printf("%d\n", x);
if x > 5 { ... }       →      if ((x > 5)) { ... }
```

---

## Common Sway Patterns

### Pattern 1: Function with Multiple Parameters
```sway
func add(a: Int, b: Int) -> Int {
    return a + b
}

func main() -> Void {
    let result = add(a: 3, b: 4)
    print(result)  // prints 7
}
```

### Pattern 2: Conditional Logic
```sway
func isPositive(x: Int) -> Bool {
    if x > 0 {
        return 1
    } else {
        return 0
    }
}
```

### Pattern 3: Loops with Accumulator
```sway
func sum(limit: Int) -> Int {
    var total: Int = 0
    var i: Int = 1
    
    while i <= limit {
        total = total + i
        i = i + 1
    }
    
    return total
}
```

### Pattern 4: Function Composition
```sway
func double(x: Int) -> Int {
    return x * 2
}

func main() -> Void {
    let result = double(x: 5)  // 10
    print(result)
}
```

---

## Data Types Quick Reference

### Basic Types
```sway
let number: Int = 42           // Integer
let decimal: Float = 3.14      // Decimal
let text: String = "Hello"     // Text
let flag: Bool = 1             // Boolean (1=true, 0=false)
```

### Optional Types
```sway
let maybe: Int? = nil          // Can be empty
let value: String? = "text"    // Can have value
```

### Type Inference
```sway
let x = 10              // Inferred as Int
let y = 3.14            // Inferred as Float
let name = "Alice"      // Inferred as String
```

---

## Language Syntax Cheat Sheet

### Variables
```sway
let x: Int = 5          // Immutable
var y: Int = 10         // Mutable
var z = 15              // Type inference
```

### Functions
```sway
func add(a: Int, b: Int) -> Int {
    return a + b
}

func greet() -> String {
    return "Hello"
}

func noReturn() -> Void {
    print(1)
}
```

### Control Flow
```sway
// If statement
if x > 5 {
    print(x)
} else {
    print(0)
}

// While loop
while i < 10 {
    print(i)
    i = i + 1
}

// Return
return x + y
```

### Operators
```sway
// Arithmetic
a + b       // Addition
a - b       // Subtraction
a * b       // Multiplication
a / b       // Division
a % b       // Modulo

// Comparison
a == b      // Equal
a != b      // Not equal
a < b       // Less than
a > b       // Greater than
a <= b      // Less or equal
a >= b      // Greater or equal

// Logical
a && b      // AND
a || b      // OR
!a          // NOT
```

---

## Troubleshooting

### Issue: Command not found
```
command not found: python3
```
**Solution:** Install Python 3
```bash
sudo apt-get install python3
```

### Issue: gcc not found
```
Error: gcc: command not found
```
**Solution:** Install gcc
```bash
sudo apt-get install build-essential
```

### Issue: Parse error with type name
```
Parse error at 5:10: Expected type name
```
**Solution:** Make sure type names are capitalized
```sway
let x: Int = 5       // ✅ Correct
let x: int = 5       // ❌ Wrong (lowercase)
```

### Issue: Undefined function
```
Compilation error: undefined reference to 'function_name'
```
**Solution:** Make sure all functions are declared before main

---

## Running Multiple Examples

### Run all examples at once:
```bash
python3 run_all_examples.py
```

### Or run specific examples:
```bash
python3 sway.py run examples/simple.sway
python3 sway.py run examples/factorial.sway
python3 sway.py run examples/loops.sway
```

---

## Next Steps

1. **Try the Examples**: Run all examples in the `examples/` directory
2. **Modify Examples**: Change the code and recompile
3. **Create New Programs**: Write your own .sway files
4. **Study Generated Code**: Look at .c files to understand the mapping
5. **Read the Docs**: Check README.md for full language reference

---

## Quick Command Reference

```bash
# View usage
python3 sway.py --help

# Build (generate C code)
python3 sway.py build program.sway

# Run (build + compile + execute)
python3 sway.py run program.sway

# Compile C directly
python3 sway.py compile program.c -o program

# View generated C
cat program.c

# Manually compile with gcc
gcc -o program program.c

# Run executable
./program
```

---

## Tips & Tricks

### Tip 1: Save compilation artifacts
The compiler creates `.c` files. Keep them for learning!
```bash
python3 sway.py build examples/factorial.sway
# Now you have examples/factorial.c to examine
```

### Tip 2: Use type inference when obvious
```sway
let x = 42              // Compiler infers Int
let y = add(a: 1, b: 2) // Compiler infers return type
```

### Tip 3: Name your parameters explicitly
```sway
func max(a: Int, b: Int) -> Int {
    // Use named arguments when calling
    return max(a: 5, b: 10)
}
```

### Tip 4: Start simple, build up
```sway
// Start with basic functions
func add(a: Int, b: Int) -> Int {
    return a + b
}

// Then add control flow
func max(a: Int, b: Int) -> Int {
    if a > b {
        return a
    } else {
        return b
    }
}

// Then add loops
func factorial(n: Int) -> Int {
    var result: Int = 1
    var i: Int = 2
    while i <= n {
        result = result * i
        i = i + 1
    }
    return result
}
```

---

## Summary

✅ You now know how to:
- Install and set up Sway
- Compile Sway programs to C
- Run the examples
- Understand the generated C code
- Write basic Sway programs
- Use common language patterns

🎉 **Happy coding with Sway!**

For more details, see:
- **README.md** - Language reference
- **EXAMPLES.md** - More examples
- **IMPLEMENTATION.md** - Technical details
- **PROJECT_SUMMARY.md** - Project overview

---

**Version**: 0.1.0 (MVP)  
**Created**: April 2026  
**Python Version**: 3.7+
