//
// Created by danie on 2/13/2024.
// Description: Implement two types of sorting algorithms: Merge sort and bubble sort.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "printCollections.h"

using std::vector;
using std::endl;

template<class T>
vector<T> vectorPart(vector<T> vector1, int begin, int end) {
    vector<T> vectorResult;
    try {
        for (int i = begin; i <= end; i++) {
            if(end >= vector1.size()){throw(std::range_error("Out of bounds"));}
            vectorResult.push_back(vector1[i]);
        }
    }catch(const std::range_error& e){
        std::cout << e.what() << endl;
        std::cout << end << " is larger than the vector max index, which is " << vector1.size() - 1 << std::endl;
        exit(EXIT_FAILURE);
    }
    //std::cout << "vectorsize: " << vectorResult.size() << std::endl;
    return vectorResult;
}

template<class T>
vector<T> mergeSort(vector<T> arrayToSort) {
    auto originalArray = arrayToSort;
    vector<T> sortedArray;
    vector<vector<T>> sortedParts;
    for(int i = 1; i <= arrayToSort.size(); i++){
        vector<T> part1 = vectorPart(originalArray, 0, (int)(originalArray.size() / (2*i)));
        vector<T> part2 = vectorPart(originalArray, (int)(originalArray.size() / (2 * i)) + 1, (int)originalArray.size() - 1);
        std::cout << printVector(part1, " ") << "| ";
        std::cout << printVector(part2, " ") << endl;
        if(part1.size() == 2){
            originalArray = part2;
            T temp1 = part1[0];
            T temp2 = part1[1];
            if(temp1 > temp2){
                part1[0] = temp2;
                part1[1] = temp1;
            }

            sortedParts.push_back(part1);
        }
        if(part1.size() == 1){

        }
    }

    std::cout << "sortedparts " << printVector(sortedParts[0], " ") << endl;

    return sortedArray;
}

template<class T>
T *copyArray(T arrayToCopy[], int arraySize) {}

int main() {
    //vector<int> array = {52, 45, 1, 90, 35}; // 1, 35, 45, 52, 90
    //vector<int> array = {38, 27, 43, 3, 9, 82, 10};
    vector<int> array = {43, 3, 9, 82, 10};

    //vector<int> newArray = mergeSort<int>(array);
    //std::cout << (int) array.size() / 2 << endl;
    auto newArray1 = vectorPart(array, 0, (int)(array.size() / 2) - 1);
    auto newArray2 = vectorPart(array, (int)(array.size() / 2), (int)array.size() - 1);

    auto sortedArray = mergeSort(array);

    //std::cout << "array:" << endl;
    std::cout << "original: " << printVector(array, " ") << std::endl;
    //std::cout << "new array:" << endl;
    //std::cout << printVector(newArray1, " ") << std::endl;
    //std::cout << printVector(newArray2, " ") << std::endl;
    std::cout << "sorted: " << printVector(sortedArray, " ") << endl;
}