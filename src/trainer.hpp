#ifndef trainer_hpp
#define trainer_hpp

#include <stdio.h>
#include "file-manager.hpp"

#define roundz(x,d) ((floor(((x)*pow(10,d))+.5))/pow(10,d))

// Define weights and bias
struct NeuralNetwork {
    float w1;
    float w2;
    float bias;
};

float sigmoid(float t);
float sigmoidDerivative(float t);
float neuralNetwork(float firstIn, float secondIn, NeuralNetwork elements);
NeuralNetwork train(NeuralNetwork elements, vector<FileLines> dataset);

#endif
