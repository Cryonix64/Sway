# Sway Programming Language

**Sway** - A Swift-inspired programming language that compiles to C/C++

## Overview

Sway is a modern, statically-typed programming language inspired by Swift with a focus on safety and clarity. The compiler transforms Sway code into efficient C code that can be compiled and executed using standard C compilers (gcc/clang).

## Key Features

✅ **Modern Swift-like Syntax**
- let/var bindings
- Function declarations with type annotations
- Structs and classes
- Enums
- Optional types (Int?, String?, etc.)
- Type inference

✅ **Safety First**
- Static typing prevents many runtime errors
- Optional types eliminate null pointer issues
- Clear variable binding semantics (let = immutable, var = mutable)

✅ **Efficient Code Generation**
- Compiles directly to C
- Zero runtime overhead
- Compatible with standard C toolchain (gcc, clang)

✅ **Modular Architecture**
- Clean separation: Lexer → Parser → AST → Codegen
- Easy to extend and maintain
- Built-in standard library functions

## Project Structure

```
sway/
├── src/
│   ├── lexer/          # Tokenization
│   │   ├── tokens.py   # Token definitions
│   │   └── lexer.py    # Lexer implementation
│   ├── parser/         # AST generation
│   │   └── parser.py   # Recursive descent parser
│   ├── ast/            # Abstract Syntax Tree
│   │   └── nodes.py    # AST node definitions
│   ├── codegen/        # Code generation
│   │   └── codegen.py  # C code generator
│   └── cli/            # Command-line interface
│       └── cli.py      # CLI implementation
├── examples/           # Example programs
├── stdlib/             # Standard library
├── sway.py             # Main entry point
└── README.md           # This file
```

## Installation & Usage

### Prerequisites
- Python 3.7+
- gcc or clang

### Running the Compiler

```bash
# Build a Sway file (generates C code)
python3 sway.py build program.sway

# Build and run a Sway file
python3 sway.py run program.sway

# Compile generated C code
python3 sway.py compile program.c -o program
```

## Language Syntax

### Variables

```sway
let x: Int = 10        // Immutable integer
let y = 20             // Type inference
var name: String = "Alice"  // Mutable string
var counter: Int       // Declaration without initialization
```

### Functions

```sway
func add(a: Int, b: Int) -> Int {
    return a + b
}

func greet(name: String) -> String {
    return "Hello, " + name
}

func sayHello() -> Void {
    print("Hello, World!")
}
```

### Control Flow

```sway
// If statements
if x > 0 {
    print(x)
} else if x == 0 {
    print(0)
} else {
    print(-1)
}

// While loops
var i: Int = 0
while i < 10 {
    print(i)
    i = i + 1
}

// For loops (basic)
for item in collection {
    print(item)
}
```

### Data Structures

#### Structs
```sway
struct Person {
    name: String,
    age: Int
}
```

#### Classes
```sway
class Dog {
    name: String,
    age: Int
    
    func bark() -> Void {
        print("Woof!")
    }
}
```

#### Enums
```sway
enum Color {
    Red,
    Green,
    Blue
}
```

### Optional Types

```sway
let maybe: Int? = nil
let value: String? = "hello"

if let actualValue = maybe {
    // Use actualValue
}
```

### Built-in Functions

```sway
print(x)  // Print to stdout
```

## Examples

### Example 1: Hello World Variant

**Sway Code** (`hello.sway`):
```sway
func greet(name: String) -> String {
    return "Hello, " + name
}

func main() -> Void {
    let greeting = greet(name: "World")
    print(greeting)
}
```

**Generated C Code** (`hello.c`):
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* greet(const char* name);
void main(void);

char* greet(const char* name) {
    return "Hello, " + name;
}

void main(void) {
    char* greeting = greet("World");
    printf("%s\n", greeting);
}
```

### Example 2: Factorial Function

**Sway Code** (`factorial.sway`):
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

### Example 3: Simple Arithmetic

**Sway Code** (`arithmetic.sway`):
```sway
func main() -> Void {
    let x: Int = 10
    let y: Int = 20
    
    print(x + y)
    print(x * y)
    print(y - x)
    print(y / x)
}
```

## Type System

### Primitive Types
- `Int` - Integer type
- `Float` - Floating point type
- `String` - String type
- `Bool` - Boolean type (true/false)
- `Void` - No return value

### Type Annotations
```sway
let x: Int = 5
let name: String = "Alice"
let active: Bool = true
```

### Optional Types
```sway
let maybeInt: Int? = nil
let maybeString: String? = "hello"
```

## Type Mapping: Sway → C

| Sway | C |
|------|---|
| Int | int |
| Float | float |
| String | const char* |
| Bool | int |
| Void | void |
| Type? | Type* |

## Compilation Pipeline

```
Sway Source Code
      ↓
   [Lexer] → Tokens
      ↓
   [Parser] → AST
      ↓
  [Codegen] → C Code
      ↓
   [gcc/clang] → Executable
```

### Stage Details

1. **Lexer** (`lexer.py`):
   - Tokenizes source code
   - Recognizes keywords, operators, literals
   - Tracks line/column for error reporting

2. **Parser** (`parser.py`):
   - Recursive descent parser
   - Builds Abstract Syntax Tree (AST)
   - Handles precedence and associativity

3. **AST** (`nodes.py`):
   - Node definitions for all language constructs
   - Program, Declarations, Statements, Expressions

4. **Codegen** (`codegen.py`):
   - Traverses AST
   - Emits C code
   - Manages symbol tables and type conversions

## Supported Features (MVP)

✅ Variable declarations (let/var)
✅ Function declarations with parameters and return types
✅ Control flow (if/else, while)
✅ Basic operators (+, -, *, /, %, ==, !=, <, >, <=, >=, &&, ||)
✅ Function calls with named arguments
✅ Struct definitions
✅ Enum definitions
✅ Basic type inference
✅ Comments (// and /* */)
✅ Print function
✅ Recursion

## Planned Features

🔜 String interpolation (\(expr))
🔜 For-in loops over arrays
🔜 Array literals and indexing
🔜 Proper method calling syntax
🔜 Generics/Templates
🔜 Error handling (try/catch)
🔜 Imports and modules
🔜 Closure support
🔜 More standard library functions
🔜 C++ backend

## Error Handling

The compiler provides helpful error messages with line and column information:

```
Parse error at 2:21: Expected type name
Lexer error at 3:5: Unterminated string
```

## Performance

Sway compiles to efficient C code with minimal overhead:
- No garbage collection overhead (stack allocation by default)
- Direct C function calls
- Inline optimization opportunities for C compiler

## Examples Included

Run the examples with:
```bash
python3 sway.py run examples/simple.sway
python3 sway.py run examples/arithmetic.sway
python3 sway.py run examples/conditions.sway
python3 sway.py run examples/factorial.sway
python3 sway.py run examples/loops.sway
```

## Contributing

The codebase is designed to be modular and extensible:
- Add new token types in `lexer/tokens.py`
- Add parsing rules in `parser/parser.py`
- Add AST nodes in `ast/nodes.py`
- Add code generation in `codegen/codegen.py`

## License

Educational/Research Project - 2026

---

**Author**: Sway Dev Team  
**Version**: 0.1.0 (MVP)
