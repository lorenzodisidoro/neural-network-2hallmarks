#include "trainer.hpp"
#include <math.h>
#include <cstdlib>

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

// Configs
int   NUMBER_OF_UPDATE = 100000;
float LEARGNING_RATE   = 0.1;

float sigmoid(float t)
{
    return 1/(1 + exp(-t));
}

float sigmoidDerivative(float t)
{
    return sigmoid(t) * (1 - sigmoid(t));
}

float neuralNetwork(float firstIn, float secondIn, NeuralNetwork el)
{
    float t = (firstIn * el.w1) + (secondIn * el.w2) + el.bias;
    return sigmoid(t);
}

NeuralNetwork train(NeuralNetwork el, vector<FileLines> inputDataset)
{
    int n = inputDataset.size();
    int m = 3;
    float dataset[n][3];
    string::size_type sz;

    // parse input dataset
    for(std::size_t i=0; i < inputDataset.size(); ++i) {
        for(std::size_t j=0; j < inputDataset[i].size(); ++j) {
            const char *item = inputDataset[i][j].c_str();
            dataset[i][j] = roundz(atof(item), 2); 
        }
    }

    // training
    for (int i = 0; i < NUMBER_OF_UPDATE; i++ )
    {
        float firstHallmark  = 0.0;
        float secondHallmark = 0.0;
        float bias           = 0.0;
        int randomIndex      = rand()%(sizeof(dataset) - 1);

        if (randomIndex >= 0 && randomIndex <= n) {
            firstHallmark  = dataset[randomIndex][0];
            secondHallmark = dataset[randomIndex][1];
            bias           = dataset[randomIndex][2];
            cout << dataset[randomIndex][0] << " - ";
            cout << dataset[randomIndex][1] << " - ";
            cout << " type: " << dataset[randomIndex][2] << '\n';
        }

        float point[3]   = { firstHallmark, secondHallmark, bias };
        float z          = (point[0] * el.w1) + (point[1] * el.w2 + el.bias);
        float prediction = sigmoid(z);
        float flagType   = point[2];
        
        float cost = (prediction - flagType);
        cost = pow(cost, 2);
        
        float partialDerivativeCostPred = 2 * (prediction - flagType);
        float partialDerivativePredZ    = sigmoidDerivative(z);
        
        // chain rule
        float partialDerivativeZW1 = point[0];
        float partialDerivativeZW2 = point[1];
        
        float partialDerivativeCostZ  = partialDerivativeCostPred * partialDerivativePredZ;
        float partialDerivativeCostW1 = partialDerivativeCostZ * partialDerivativeZW1;
        float partialDerivativeCostW2 = partialDerivativeCostZ * partialDerivativeZW2;
        float partialDerivativeCostB  = partialDerivativeCostZ * 1;
        
        // update weights and bias using learning rate
        el.w1   = el.w1 - LEARGNING_RATE * partialDerivativeCostW1;
        el.w2   = el.w2 - LEARGNING_RATE * partialDerivativeCostW2;
        el.bias = el.bias - LEARGNING_RATE * partialDerivativeCostB;
    }
    
    return el;
}
