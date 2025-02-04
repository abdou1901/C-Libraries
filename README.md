# C-Libraries Repository

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Repository Structure](#repository-structure)
- [How to Use](#how-to-use)
- [Documentation](#documentation)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction
This repository contains a collection of C libraries designed to provide reusable functions for common programming tasks. Each library focuses on a specific domain (numbers, strings, arrays, matrices, and ciphers) and includes comprehensive testing files, implementation files, and header files. Additionally, full documentation is provided to help users understand and utilize these libraries effectively.

Whether you're a beginner or an experienced developer, this repository aims to simplify coding by offering modular, well-documented, and tested functions.

## Features
- **Modular Design**: Each library is self-contained with its own .c, .h, and test files.
- **Comprehensive Testing**: Every function in the libraries has been rigorously tested using interactive test files.
- **Full Documentation**: A single consolidated documentation file explains all functions across all libraries.
- **Extensible**: Easily add new functions or libraries as needed.
- **Cross-Platform Compatibility**: Written in standard C, ensuring compatibility across platforms.

## Repository Structure
```
C-Libraries/
├── numbers/
│   ├── main.c       # Test file for Numbers Library
│   ├── num.c    # Implementation file
│   ├── num.h    # Header file
├── strings/
│   ├── main.c       # Test file for Strings Library
│   ├── string.c    # Implementation file
│   ├── string.h    # Header file
├── arrays/
│   ├── main.c       # Test file for Arrays Library
│   ├── array.c     # Implementation file
│   ├── array.h     # Header file
├── matrices/
│   ├── main.c       # Test file for Matrices Library
│   ├── matrice.c   # Implementation file
│   ├── matrice.h   # Header file
├── ciphers/
│   ├── main.c       # Test file for Ciphers Library
│   ├── cipher.c    # Implementation file
│   ├── cipher.h    # Header file
├── docs/            # Documentation folder
│   └── documentation.pdf  # Full documentation of all libraries
└── README.md        # This file
```


## How to Use
### Clone the Repository:
```bash
git clone https://github.com/abdou1901/C-Libraries.git
cd C-Libraries
```
### Compile and Run Tests:
Navigate to the desired library folder and compile the test file (main.c) with the corresponding .c file:
```bash
gcc -o test_numbers main.c num.c
./test_numbers
```
Repeat this process for other libraries.

### Include Libraries in Your Projects:
To use any library in your projects, include the respective .h file and link the .c file during compilation:
```bash
gcc -o my_program my_program.c num.c -I./numbers
```

## Documentation
A detailed documentation file (`docs/documentation.md`) is included in the `docs` folder. It provides explanations, examples, and usage instructions for every function across all libraries.

## Contributing
Contributions are welcome! If you'd like to contribute, please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and ensure they are well-documented and tested.
4. Submit a pull request describing your changes.

## License
Feel free to use, modify, and distribute the code as per the terms of the license.

## Contact
If you have any questions or suggestions, feel free to reach out via GitHub Issues or email me at `abdouzengla0001@gmail.com`.

Thank you for visiting this repository! We hope these libraries will be useful in your projects. **Happy coding!** 😊
