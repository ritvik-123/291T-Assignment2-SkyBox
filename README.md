# Assignment-2 SkyBox

> **Course/Assignment:** Assignment 2 Skybox
> **Author:** Ritvik  
> **Language/Tech:** C++, OpenGL, GLUT / FreeGLUT

---

## 1) Overview

This repository contains an OpenGL/GLUT-based game or assignment developed in C++.

### Project-Specific Description
> Implemented SkyBox for an immersive game environment

---

## 2) Requirements / Dependencies

- C++ Compiler (GCC / MinGW / MSVC)
- OpenGL
- GLUT or FreeGLUT
- Code::Blocks (recommended for Windows users)

---

## 3) How to Build & Run

### Option A — Windows (Code::Blocks)
1. Install **Code::Blocks** with **MinGW**.
2. Open `Assignment2_SkyBoxPly.cbp` in Code::Blocks.
3. Make sure the compiler is properly configured.
4. Click **Build & Run (F9)**.

### Option B — Windows (Command Line – MinGW)
```bash
g++ main.cpp -o Assignment2_SkyBoxPly.exe -lopengl32 -lglu32 -lfreeglut
