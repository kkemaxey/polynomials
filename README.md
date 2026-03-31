# ➗ Linked-List Polynomial Processor ➗

> A specialized C++ engine designed to perform arithmetic operations on polynomials using dynamic linked list structures. This system handles complex algebraic expressions with both positive and negative exponents, ensuring high precision in term management and memory allocation.

## 🎮 How to Play
*   **Setup**: Enter the number of polynomials you wish to process (up to 10). To exit the program, simply enter `0`.
*   **Inputting Terms**: Enter your polynomials in decreasing order of exponents (e.g., `5x^2 + 3x - 1`). The parser is flexible and ignores optional spaces between coefficients and operators.
*   **Automatic Calculation**: Once the polynomials are entered, the system automatically computes and displays both the **Sum** and the **Product** of the entire set.
*   **Formatting**: The output is standardized with square brackets, aligned "=" operators, and decreasing exponent order for professional readability.
*   **Variable Rules**: Constant terms are entered as integers, and terms with an exponent of 1 are entered simply as `x`.

## ✨ Features
- **Linked-List Architecture**: Uses a custom `ATerm` struct and pointer-based logic to store coefficients and exponents dynamically.
- **Advanced Algebra**: Fully supports both **positive and negative exponents**, as well as positive and negative coefficients.
- **Polynominal Arithmetic**: Includes robust recursive or iterative logic to add and multiply multiple polynomials while combining like terms.
- **Smart Parsing**: A custom string-handling engine that processes raw user input, handling various spacing styles and mathematical symbols (`^`, `+`, `-`).
- **Memory Management**: Efficiently navigates and cleans up dynamic linked list nodes to prevent memory leaks during complex multiplication cycles.

## 🛠️ Tech Stack
- **Language**: C++
- **Data Structure**: Singly Linked List (Pointers).
- **Dependencies**: Standard I/O and String handling libraries only.
- **Input Format**: 
    - **Polynomials**: `cx^k` (e.g., `3x^2 - 4x + 1` or `-1 + x^-2`).
    - **Termination**: Enter `0` at the "Number of polynomials" prompt to quit.

## 🚀 Quick Start

### Compilation

If you have the files locally and the g++ compiler, first navigate to the file location and just run `g++ polyFunctions.cpp polyDriver.cpp -o [your_desired_file_name].exe`

To clone and run locally:
```bash
git clone https://github.com
cd polynomials
