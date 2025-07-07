# Virtual_City_OpenGL

**Virtual_City_OpenGL** is an immersive cityscape simulation developed using **C++** and **GLUT** (OpenGL Utility Toolkit). It showcases a dynamic 3D urban environment with support for **day**, **night**, and **rain** modes, enhanced with interactive features such as animated neon signboards and laser lights. The project aims to demonstrate graphical rendering, basic animation, and user interactivity using OpenGL.

---

##  Features

-  **Cityscape Rendering**: Real-time visualization of buildings and skyline.
-  **Dynamic Weather Modes**: Toggle between day, night, and rain.
-  **Integrated Music**: Custom background music for each mode.
-  **Interactive Elements**:
  - Toggle neon signboards and laser lights.
  - Keyboard-controlled environment switching.
-  **Built with C++ & GLUT**: Lightweight and cross-platform.

---

##  Installation

### 1. Clone the repository:

```bash
git clone https://github.com/anaspui/Virtual_City_OpenGL.git
cd Virtual_City_OpenGL
```
### 2. Build the project Use a C++ compiler with OpenGL and GLUT linked. Example with g++:
```bash
g++ main.cpp -o VirtualCity -lGL -lGLU -lglut
```

### 3. Usage
 Key Bindings

| Key | Action |
| --- | --- |
| d | Switch to Day Mode |
| n | Switch to Night Mode |
| 1 | Enable Ghost Eating Doughnut signboard |
| 2 | Disable Ghost Eating Doughnut signboard |
| 3 | Enable Laser Light |
| 4 | Disable Laser Light |
| 5 | Activate Rain Mode |
| 6 | Deactivate Rain Mode |

### 4. Technologies Used

-   C++
-   OpenGL
-   GLUT (OpenGL Utility Toolkit)
