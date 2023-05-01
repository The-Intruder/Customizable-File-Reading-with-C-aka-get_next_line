<br/>
<p align="center">
  <a href="https://github.com/The-Intruder/Customizable-File-Reading-with-C-aka-get_next_line">
    <img src="https://images.freeimages.com/fic/images/icons/2813/flat_jewels/512/file.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Customizable File Reading with C <em>(get_next_line)</em></h3>

  <p align="center">
    Get Next Line - The efficient and reliable solution for reading lines from a file descriptor.
    <br/>
    <br/>
    <a href="https://github.com/The-Intruder/Customizable-File-Reading-with-C-aka-get_next_line/issues">Report Bug</a>
    .
    <a href="https://github.com/The-Intruder/Customizable-File-Reading-with-C-aka-get_next_line/issues">Request Feature</a>
  </p>
</p>

<div  style="display: flex; justify-content: center;">
<a  href="https://twitter.com/i_am_amine" target="_blank">
  <img  alt="Twitter Follow"  src="https://img.shields.io/twitter/follow/i_am_amine?style=social">
</a>
<img  src="https://img.shields.io/github/repo-size/The-Intruder/Customizable-File-Reading-with-C-aka-get_next_line"  alt="Repo Size">
<img  src="https://img.shields.io/github/last-commit/The-Intruder/Customizable-File-Reading-with-C-aka-get_next_line"  alt="Last Commit">
<img alt="GitHub" src="https://img.shields.io/github/license/The-Intruder/Customizable-File-Reading-with-C-aka-get_next_line">
</div>

## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Authors](#authors)
* [Acknowledgements](#acknowledgements)

## About The Project

Get Next Line (GNL) is a versatile and efficient function designed to read lines from a file descriptor. It provides a robust and convenient solution for extracting data from files, making it an essential tool for file parsing and processing tasks.

It basically aims to create a function that reads a line from a file descriptor until a newline character ('\n') is encountered. It handles different file descriptors, allowing simultaneous reading from multiple sources. This function is particularly useful when dealing with large files or when processing data line by line.


## Built With

#### C Programming Language

The Get Next Line function is implemented using the C programming language, leveraging its low-level capabilities for efficient file handling and memory management.

#### Standard C Libraries

The function utilizes standard C libraries such as `<unistd.h>` and `<stdlib.h>` for file operations, memory allocation, and string manipulation.

#### Operating System APIs

The Get Next Line function interacts with operating system APIs to read data from file descriptors, providing platform-independent file handling capabilities.

#### Text Editor/IDE

Any preferred text editor or integrated development environment (IDE) can be used for writing and editing the Get Next Line function code.

#### Compiler

The Get Next Line function can be compiled using a C compiler such as GCC (GNU Compiler Collection) or Clang, ensuring compatibility across different platforms and systems.


## Getting Started

To get started with the Get Next Line project, follow the steps below:

### Prerequisites

Before starting the Get Next Line project, ensure that you have the following prerequisites:

1. C Compiler:
   - You need a C compiler installed on your system to compile the source code.
   - The most commonly used C compilers are GCC (GNU Compiler Collection) and Clang.
   - Make sure the compiler is properly installed and accessible from the command line.

2. Operating System:
   - The Get Next Line function is typically implemented for Unix-like systems (e.g., Linux, macOS).
   - Ensure that you are using a compatible operating system that supports the necessary system calls and APIs.

Once you have the above prerequisites in place, you are ready to start working on the Get Next Line project.

### Installation
Getting Started:
To get started with the Get Next Line project, follow the steps below:

1. Clone the Repository:
   - Open your preferred terminal or command prompt.
   - Change the current working directory to the location where you want to clone the repository.
   - Run the following command:
     ```
     git clone https://github.com/The-Intruder/Customizable-File-Reading-with-C-aka-get_next_line get_next_line
     ```
   - This will create a local copy of the Get Next Line project on your machine.

2. Navigate to the Project Directory:
   - Change the current working directory to the project directory:
     ```
     cd get_next_line
     ```

3. Build the Project:
   - Use the provided Makefile to build the Get Next Line function:
     ```
     make bonus
     ```
   - This will compile the source files and create the executable.

Congratulations! You are now ready to use and further develop the Get Next Line function for efficient file reading and processing.

## Usage

To use the Get Next Line function in your project, follow these steps:

1. Include the Header File:
   - In the source file where you want to use the Get Next Line function, include the header file "get_next_line.h".
   - Add the following line at the beginning of your source file:
     ```
     #include "get_next_line.h"
     ```

2. Call the Get Next Line Function:
   - To read the next line from a file descriptor, use the following function call:
     ```
     char *get_next_line(int fd);
     ```
   - Pass the file descriptor `fd` from which you want to read the next line.
   - The function will return the line read from the file descriptor, which is a pointer to a character (`char*`).
   - The function returns a pointer to a character if a line was read successfully, `NULL` if the end of the file was reached or in case of an error.

3. Process the Read Line:
   - After calling the Get Next Line function, you can process the read line as needed in your project.
   - The line read from the file descriptor is returned function call.
   - You can manipulate and use the returned pointer to perform operations such as printing, parsing, or further processing.

4. Free Allocated Memory:
   - It's important to free the memory allocated by the Get Next Line function to avoid memory leaks.
   - After you have finished using the line read from the file descriptor, free the memory using the following function call:
     ```
     void free(void *addr);
     ```
   - Pass the address of the returned value to the `free` function to free the memory.

5. Repeat the Process:
   - To read the next line from the file descriptor, repeat steps 2-4.
   - The Get Next Line function keeps track of the file descriptor and its progress, allowing you to retrieve successive lines.

Make sure to check the return value of the Get Next Line function and handle any errors or end-of-file conditions appropriately in your code.

## Roadmap

Here is a roadmap that outlines the steps to take in order to enhance and expand the Get Next Line project:

1. Refactor and Optimize:
   - [ ] Review your implementation and identify areas where you can optimize the code or improve its structure.
   - [ ] Consider revisiting your algorithms and data structures to enhance performance.

2. Error Handling:
   - [ ] Improve the error handling capabilities of the Get Next Line function.
   - [ ] Ensure that appropriate error codes or error messages are returned to the caller in case of failures or exceptional conditions.
   - [ ] Handle edge cases such as invalid file descriptors or unexpected input gracefully.

3. Support for Additional File Descriptors:
   - [ ] Extend the Get Next Line function to handle reading from multiple file descriptors simultaneously.
   - [ ] Modify your implementation to manage and track the progress of each file descriptor independently.

4. Buffer Management:
   - [ ] Explore different strategies for buffer management to improve memory usage and efficiency.
   - [ ] Experiment with different buffer sizes and evaluate their impact on performance.

5. Testing and Validation:
   - [ ] Create a comprehensive test suite to validate the correctness and reliability of the Get Next Line function.
   - [ ] Include tests for various file types, edge cases, and boundary conditions.
   - [ ] Ensure that your implementation handles different line termination characters correctly (e.g., newline, carriage return, or a combination).

6. Documentation and Comments:
   - [ ] Review and update the code documentation to ensure it is clear, concise, and follows a consistent style.
   - [ ] Add comments to complex or critical sections of the code to enhance readability and maintainability.

7. Performance Benchmarking:
   - [ ] Conduct performance benchmarking to measure the efficiency of your implementation.
   - [ ] Compare the performance of your Get Next Line function with other existing solutions and identify areas for improvement.

8. Community Contributions:
   - [ ] Consider contributing your Get Next Line implementation to open-source projects or communities.
   - [ ] Share your code, insights, and experiences to help others learn and benefit from your work.

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.
* If you have suggestions for adding or removing projects, feel free to [open an issue](https://github.com/The-Intruder/Customizable-File-Reading-with-C-aka-get_next_line/issues/new) to discuss it, or directly create a pull request after you edit the *README.md* file with necessary changes.
* Please make sure you check your spelling and grammar.
* Create individual PR for each suggestion.ell.

### Creating A Pull Request

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

Distributed under the MIT License. See [LICENSE](https://github.com/The-Intruder/Customizable-File-Reading-with-C-aka-get_next_line/blob/main/LICENSE.md) for more information.

## Authors

* **Mohamed Amine Naimi** - *Comp Sci Student* - [Mohamed Amine Naimi](https://github.com/The-Intruder/) - *Built the get_next_line project*

## Acknowledgements

* [The-Intruder](https://github.com/The-Intruder/)
