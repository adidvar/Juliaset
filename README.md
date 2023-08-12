# Julia Set Renderer

<!--![Julia Set](screenshot.png) -->

This is a C++ project that allows you to render and visualize the Julia Set using OpenGL shaders. The Julia Set is a famous fractal in mathematics, and this project provides a graphical representation of it. The project uses the Conan package manager for handling dependencies and includes GPL-3.0 license for distribution and use.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Introduction

The Julia Set is a fractal defined in the complex plane. This project allows you to explore and visualize the intricate patterns of the Julia Set using OpenGL shaders for rendering. With the help of the Conan package manager, the project simplifies dependency management and ensures easy setup.

## Features

- Render the mesmerizing Julia Set fractal.
- Utilize OpenGL shaders for efficient rendering.
- Easily manage project dependencies with Conan.
- Simple and intuitive interface for user interaction.

## Getting Started

To get started with the Julia Set Renderer, follow these steps:

1. **Clone the Repository:** Clone this repository to your local machine using the following command:

   ```
   git clone https://github.com/adidvar/Juliaset.git
   ```

2. **Navigate to Project Directory:** Move to the project directory:

   ```
   cd Juliaset
   ```

3. **Install Dependencies:** Use the Conan package manager to install the required dependencies.

   ```
   conan install .
   ```

4. **Build the Project:** Build the project using your preferred build system (CMake, Make, Visual Studio, etc.).

5. **Run the Application:** Copy shaders to app directory.Execute the compiled application and explore the Julia Set fractal.

## Dependencies

The project uses the following dependencies, which will be automatically installed using Conan:

- OpenGL: A graphics library for rendering 2D and 3D graphics.
- GLFW 3.3.8
- GLAD 0.1.36
- GLM
- conan

## Installation

To install the Julia Set Renderer, follow the steps mentioned in the [Getting Started](#getting-started) section. Make sure you have Conan installed before proceeding.

## Usage

After building and running the application, you will be presented with a window displaying the rendered Julia Set fractal. Use the provided controls to adjust the parameters of the fractal and explore its intricate patterns. Interact with the application to zoom in, zoom out, and pan across the fractal.

## License

This project is licensed under the GNU General Public License v3.0. For more details, see the [LICENSE](LICENSE) file.

---

Feel free to contribute to the project by submitting issues or pull requests. If you have any questions or suggestions, please don't hesitate to contact us.
