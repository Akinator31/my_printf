# my_printf

[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))  
**my_printf** is a C programming project that aims to replicate the functionality of the standard `printf` function. This project is part of the Epitech curriculum and serves as an introduction to low-level programming concepts, variadic functions, and formatted output handling.

---

## 📖 About the Project

The goal of **my_printf** is to understand and implement the logic behind the widely-used `printf` function available in the C standard library. This involves handling formatted strings, processing various data types, and creating a modular and efficient implementation.

Through this project, developers will gain deeper insights into:

- Variadic function handling (`stdarg.h`)
- Format specifiers (e.g., `%d`, `%s`, `%c`, etc.)
- String manipulation
- Modular and reusable code design in C

---

## 🚀 Features

- **Custom Format Specifiers**  
  Supports a subset of `printf`'s format specifiers, including:
  - `%d` / `%i`: Integer
  - `%s` / `%S`: String
  - `%c`: Character
  - `%u`: Unsigned integer
  - `%x` / `%X`: Hexadecimal (lowercase/uppercase)
  - `%o`: Octal
  - `%%`: Percent sign
  - `%p`: Pointer
  - `%n`: Get number of char
  - `%f` / `%F`: Float (lowercase/uppercase)
  - `%e` / `%E`: Scientific notation (mantissa/exponent), lowercase/uppercase
  - `%b`: Binary
  - `%a`: Hexadecimal floating point

- **Error Handling**  
  Handles edge cases and invalid input gracefully.

- **Optimized Performance**  
  Designed with efficiency in mind for handling real-time formatted output.

---

## 🛠️ Technologies Used

- **C Programming Language**: 95%  
  The core language for the project, focusing on low-level capabilities and performance.

- **Makefile**: 5%  
  Automates the build process for compiling the project efficiently.

---

## 📂 Project Structure

```
my_printf/
├── my_printf.c         # Core implementation of the printf function
├── lib/my/             # Additionals functions
├── src/                # Source code files
│   ├── flags/          # (-, +, , #, 0)
│   ├── specifiers/     # (%d, %i, %u, %c, etc.)
|   └── utils           # Utils files
├── include/            # Header files
│   └── my.h            # Function prototypes and macros
├── tests/              # Criterion tests
├── Makefile            # Build automation
└── README.md           # Project documentation
```

---

## 📝 Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/Akinator31/my_printf.git
   cd my_printf
   ```

2. Build the project using the provided `Makefile`:
   ```bash
   make
   ```

3. Include `my_printf` in your project:
   ```c
   #include "my_printf.h"

   int main() {
       my_printf("Hello, %s! The number is %d.\n", "world", 42);
       return 0;
   }
   ```

4. Run your program:
   ```bash
   ./your_program
   ```

---

## 🧪 Testing

To ensure the reliability of **my_printf**, test cases have been provided. Run the tests with the following command:
```bash
make tests
```

---

## 🎯 Goals of the Project

This project is designed to:

1. Deepen understanding of variadic functions and argument handling.
2. Develop an appreciation for the complexity of standard library functions.
3. Practice memory management and error handling in C.
4. Improve debugging and testing skills.

---

#-42
