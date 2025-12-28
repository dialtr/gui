# Basic GUI App

A portable, standard desktop GUI application built with C++ and wxWidgets. This project serves as a starting framework for cross-platform desktop development (Linux, macOS, Windows).

## Features
*   **Cross-Platform**: Runs natively on major operating systems.
*   **Standard UI**: Includes standard File and Help menus.
*   **Dependencies**: Minimal dependencies (wxWidgets 3.2+, CMake).

## Prerequisites
*   **C++ Compiler** (GCC 9+, Clang, or MSVC)
*   **CMake** (3.16 or newer)
*   **wxWidgets** (3.2 or newer)

### Installing Dependencies (Debian/Ubuntu)
```bash
sudo apt update
sudo apt install cmake libwxgtk3.2-dev build-essential
```

## Build and Run

1.  **Configure:**
    ```bash
    cmake .
    ```

2.  **Build:**
    ```bash
    make
    ```

3.  **Run:**
    ```bash
    ./BasicGuiApp
    ```

## License
This project is licensed under the BSD 3-Clause License - see the [LICENSE](LICENSE) file for details.
