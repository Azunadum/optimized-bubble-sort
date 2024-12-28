#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iomanip>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++; // Increment comparison count
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swaps++; // Increment swap count
            }
        }
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
        bubbleSort(tempArr);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);

        totalTime += duration.count();
    }

    double averageTime = totalTime / 3.0;
    std::cout << std::fixed << std::setprecision(4) << "Average time taken to sort: " << averageTime << " seconds" << std::endl;

    return 0;
}