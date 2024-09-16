# XFiber Project - Minimum Spanning Tree (MST) using Prim's Algorithm

## Project Overview

This project simulates the task of installing fiber in a new neighborhood for XFiber company. The goal is to find the Minimum Spanning Tree (MST) to minimize the installation cost of fiber using Prim's Algorithm.

### Features:
- Graph-based representation of the neighborhood paths with weights indicating installation costs.
- Reads input from a text file (`fiberdata.txt`) which contains vertices, edges, and associated costs.
- Implements Prim's Algorithm to compute the MST.
- Outputs the selected paths and the total cost for fiber installation.

### Files:
- `main.cpp`: Contains the implementation of the Prim's Algorithm for MST.
- `fiberdata.txt`: Input file with vertices, edges, and weights.

### How to Run:
1. Ensure you have a C++ compiler installed.
2. Compile the `main.cpp` file:
   ```bash
   g++ main.cpp -o xfiber_mst
3. ./xfiber_mst fiberdata.txt

### Example Output
Selected paths for fiber installation:
A - B: 10
B - C: 15
Total cost: 25

### Author
Sizwe Tafane
