# CLI Calculator (C++)

A simple command-line calculator implemented in C++.

This project was created to practice parsing and operator precedence.

## Features
- Supports basic operations: +, -, *, /
- Handles multi-digit integers
- Implements operator precedence (* and / before + and -)
- Basic input validation
- Division by zero handling

## Example

Input:
12 + 3 * 4

Output:
Result: 24

## Limitations
- No support for negative numbers yet (e.g. -5 + 4)
- No support for floating-point numbers (e.g. 2.5 + 6)
- No parentheses support

## Future Improvements
- Add support for negative numbers (unary minus)
- Add floating-point support
- Add parentheses handling
- Improve input validation

## How to Run

### Compile
```bash
g++ main.cpp -o calc
```

### Run
```bash
./calc
```

(On Windows, run `calc.exe`)

## Author
[quedo-swe](https://github.com/quedo-swe)
