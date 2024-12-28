#include <iostream>// final na yata
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iomanip>

void improvedOptimizedBubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    int unsortedPortion = n;
    int comparisons = 0;
    int swaps = 0;

    for (int iteration = 0; iteration < n; iteration++) {
        bool isSorted = true; // Flag to detect if the array is already sorted
        int lastSwapIndex = 0;

        for (int j = 0; j < unsortedPortion - 1; j++) {
            comparisons++; // Increment comparison count
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                lastSwapIndex = j + 1;
                isSorted = false; // Reset flag to false if a swap is detected
                swaps++; // Increment swap count
            }
        }

        if (isSorted) {
            break; // If no swaps were made, the array is already sorted
        }

        unsortedPortion = lastSwapIndex; // Update the unsorted portion of the array
    }

    std::cout << "Comparisons: " << comparisons << std::endl;
    std::cout << "Swaps: " << swaps << std::endl;
}

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        std::cerr << "Please check that the file exists and is in the correct location." << std::endl;
        return 1;
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: File is empty." << std::endl;
        return 1;
    }

    std::vector<int> arr;
    int num;
    while (file >> num) {
        arr.push_back(num);
    }

    std::cout << "Initial List: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    double totalTime = 0.0;
    for (int i = 0; i < 3; i++) {
        std::vector<int> tempArr = arr; // Create a temporary copy of the array

        // Measure the time it takes to sort the array
        auto start = std::chrono::high_resolution_clock::now();
        improvedOptimizedBubbleSort(tempArr);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);

        totalTime += duration.count();
    }

    double averageTime = totalTime / 3.0;
    std::cout << std::fixed << std::setprecision(4) << "Average time taken to sort: " << averageTime << " seconds" << std::endl;

    return 0;
}