//
//  @author: Lorenzo D'Isidoro <lorenzo.disidoro@gmail.com>
//  Copyright © 2019 Lorenzo D'Isidoro. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "./src/trainer.hpp"
#include "./src/file-manager.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Running neural network \n";
    cout << "Inizialize neural network weights and bias... \n";
    
    // Training
    NeuralNetwork elements;
    elements.w1 = ((double) rand() / (RAND_MAX))   + 0.1;
    elements.w2 = ((double) rand() / (RAND_MAX))   + 0.1;
    elements.bias = ((double) rand() / (RAND_MAX)) + 0.1;
    
    cout << "W1 = " << elements.w1  << "\n";
    cout << "W2 = " << elements.w2  << "\n";
    cout << "BIAS = " << elements.bias << "\n";
    
    char cwd[FILENAME_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        cout << "An error occurred: getcwd() error \n";
        return 1;
    }
    
    std::string fileName ("/training_dataset.csv");
    string path = cwd + fileName;
    vector<FileLines> dataset = getCSVFileLines(path);

    elements = train(elements, dataset);
    
    // Input/Output
    float firstHallmark;
    float secondHallmark;
    cout << "Please enter first characteristic value: ";
    cin >> firstHallmark;
    cout << "Please enter second characteristic value: ";
    cin >> secondHallmark;

    cout << "Input one: " << firstHallmark << "\n";
    cout << "Input two: " << secondHallmark << "\n";

    float prevision = neuralNetwork(firstHallmark, secondHallmark, elements);
    cout << "Prevision: " << prevision << "\n";
    // ToDo: print type 1 or 2
    
    return 0;
}
