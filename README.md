DataCore
A C++ simulation of data processing under resource constraints, mimicking embedded systems like microcontrollers in spaceflight, engineering, and science. Sorts sensor data within a 1 KB memory limit, optimizes efficiency with bubble sort, and ensures reliability through robust input validation and error handling. Tracks performance metrics—comparisons, swaps, and runtime—for critical applications. 🌌
Features

Resource Constraints: Enforces a 1 KB memory limit, simulating embedded environments.
Data Processing: Sorts random sensor readings (0–100°C) using bubble sort with early termination.
Efficiency: Measures comparisons, swaps, and runtime with std::chrono for performance optimization.
Reliability: Validates user input and handles errors gracefully.
Broad Applicability: Designed for spaceflight (e.g., spacecraft telemetry) but extends to automotive, IoT, and scientific data analysis.

Prerequisites

C++ compiler (e.g., g++, clang++) supporting C++11 or later.
Standard C++ libraries (<iostream>, <vector>, <random>, <chrono>, <iomanip>, <utility>).

How to Run

Clone the repository:git clone https://github.com/Benjaminwonder/DataCore.git
cd DataCore


Compile:g++ main.cpp -o datacore


Run:./datacore


Enter the number of sensor readings (e.g., 16 for a small dataset, 300 to test memory limits).

Example Outputs
16 Readings
Welcome to DataCore!
Enter number of sensor readings (e.g., 100): 16
Original Array: 23.45 67.89 12.34 ... 45.67
Memory used by the array: 64 bytes
Sorted Array: 12.34 23.45 45.67 ... 67.89
Comparisons: 120, Swaps: 45, Time: 0.02 ms

300 Readings
Welcome to DataCore!
Enter number of sensor readings (e.g., 100): 300
Original Array: 45.67 89.12 34.56 ... 78.90
Memory used by the array: 1200 bytes
Error: Memory limit exceeded. The array size exceeds 1 KB (1024 bytes). No swaps made.

Applications

Aerospace: Processes spacecraft sensor data (e.g., telemetry, thermal readings).
Engineering: Optimizes embedded systems in automotive ECUs, IoT devices, and robotics.
Science: Analyzes experimental data under resource constraints.
Industry: Enhances real-time data handling in telecommunications and healthcare devices.

Future Enhancements

Implement insertion sort to compare with bubble sort.
Add file input/output for sensor data.
Visualize performance metrics with charts or graphs.

License
MIT License

