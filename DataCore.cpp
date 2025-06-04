// Building a C++ application that simulates data processing under resource constraints, like embedded systems in engineering and science.
// Goal: Sort sensor data within a 1 KB memory limit, tracking efficiency and reliability for universal applications.

#include <iostream>
#include <utility> // For std::swap
#include<random> // For random number generation
#include <vector> 
#include <iomanip> // for std::setprecision
#include <chrono> // For measuring time

// std::vector is a dynamic array that can grow and shrink in size.
// Using std::vector for flexibility in this simulation, though C-style arrays are more common in embedded systems
// std::vector manages dynamic memory, which can be less predictable in embedded systems (heap allocation).
//  For now, it’s fine for learning

// Setting up some global constants
const size_t MEMORY_LIMIT = 1024; // Memory limit in bytes (1 KB)

// Defining a struct to hold sensor data
struct SortMetrics{
    int swaps; // Number of swaps made during sorting
    int comparisons; // Number of comparisons made during sorting.
    double time_ms;
};

// Change the function declaration
SortMetrics sortdata(std::vector<float>& arr);
std::vector<float> generateRandomSensorData(size_t number);




// Main function
int main (){
    using std::cout;
    using std::cin;
   

    size_t user; // Variable to hold user input for number of sensor readings
    cout<<"Welcome to DataCore!\n\n";

    
    do { 
        cout << "Enter number of sensor readings (e.g., 100): ";
        cin >> user;
        if(cin.fail() || user <= 0) {
            cout << "Please enter a positive number greater than zero: ";
            cin.clear(); // clear error state if input was invalid (e.g., a letter)
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            user = 0; // reset user to ensure loop continues
        }
    } while(user <= 0);// Making sure the user input is positive

    
    std::vector<float> arr = generateRandomSensorData(user); // Generate # random numbers as sensor data
    
        
    //Printing the original array
    cout<<"Original Array: ";

    // Ensureing the array is not too large to display
    cout<<std::setprecision(2)<<std::fixed; // Set precision for floating-point numbers
    if(arr.size() >20){
        cout<< "Too many elements to display. Showing first 10 and last 10 elements: \n";
        for(int i = 0; i<10;i++){

            cout<<arr[i]<<", "; // display first 10 elements
        }

        cout << "... "; // Separator

        for(int i = arr.size()-10; i< arr.size(); i++){
            cout<<arr[i]<<", "; // display last 10 elements
        }
    } 
    
    else{

            for(int i = 0; i < arr.size(); i++){
            cout<<arr[i]<<" ";
        }
    }



    //Spacing out the output for better readability
    cout<<"\n\n";

    // Call sortdata and store the swap count (sortdata now handles memory check)
    SortMetrics metrics = sortdata(arr); 
    if (metrics.swaps >= 0) {
        cout << "Sorted Array: ";
        if(arr.size() > 20){
            for(int i = 0; i < 10; i++){
                cout << arr[i] << " ";
            }
            cout << "... ";
            for(size_t i = arr.size() - 10; i < arr.size(); i++){
                cout << arr[i] << " ";
            }
        } else {
            for(size_t i = 0; i < arr.size(); i++){
                cout << arr[i] << " ";
            }
        }
        cout << "\n\n";
        cout << "Comparisons: " << metrics.comparisons << ", Swaps: " << metrics.swaps << ", Time: " << metrics.time_ms << " ms\n"; }


        return 0; // Successful execution
} 





// Function to sort an array using bubble sort algorithm
// This function sorts the array in Ascending order and checks memory constraints
SortMetrics sortdata(std::vector<float>& arr){
    using std::cerr;
    using std::cout;

    SortMetrics metrics = {0, 0, 0.0}; // Initialize SortMetrics with zero values

    if(arr.size() <= 0){
        cerr<<"Error: Array size must be greater than zero." << std::endl;
        return metrics; // Return 0 if the array is empty
    }

    float memoryUsed = arr.size() * sizeof(float);
    cout << "Memory used by the array: " << memoryUsed << " bytes" << std::endl;
    if(memoryUsed > MEMORY_LIMIT){
        // If the memory used exceeds 1 KB (1024 bytes), print an error message and return -1
        cerr<< "Error: Memory limit exceeded. The array size exceeds 1 KB (1024 bytes). No swaps made." << std::endl;
        return metrics;
    }

    auto start = std::chrono::high_resolution_clock::now();
    for(size_t i=0; i < arr.size()-1; i++){
        bool swapped = false;

        for(size_t j = 0; j < arr.size()-i-1; j++){
            metrics.comparisons++; // Count each comparison

            // Compare adjacent elements
            if(arr[j] > arr[j+1]){
                // swap elements
                std::swap(arr[j],arr[j+1]);
                swapped = true;
                metrics.swaps++; // counting the number of swaps
            }
        }
         
        if(!swapped){
            break; // if no two elements were swapped, the array is sorted
        }
        
    }
    auto end = std::chrono::high_resolution_clock::now();
    metrics.time_ms = std::chrono::duration<double, std::milli>(end - start).count();

    return metrics;
};




// Creating a new function to generate random( sensor) data
// This function is not used in the current code but can be useful for generating test data in the future.
std::vector<float> generateRandomSensorData(size_t number){
    std:: vector<float> sensorData; // Vector to hold sensor data
    std::random_device rd;// Obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_real_distribution<float> dis(0.0f, 100.0f); // Define the range for random numbers
    for(size_t i =0; i<number;i++){ // Generate 100 random sensor data points}
        sensorData.push_back(dis(gen)); // Add random number to the vector
    }
    return sensorData; // Return the vector containing random sensor data
}






// This code simulates sorting data in a memory-constrained environment, like an embedded system (microcontroller with limited RAM).
// It uses a vector to hold the data and checks if the memory used by the vector exceeds 1 KB (1024 bytes).

// Goal: Ensure the array fits within a 1 KB (1024 bytes) memory limit, 
//as if running on a microcontroller with limited RAM.