#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Linear activation function
double linear(double x) {
    return x;
}

// Normalize input data to the range [0, 1]
double normalize(double x, double min, double max) {
    return (x - min) / (max - min);
}

// De-normalize output data
double denormalize(double x, double min, double max) {
    return x * (max - min) + min;
}

// Neural Network structure
typedef struct {
    double weight;
    double bias;
} NeuralNetwork;

// Initialize the neural network with random weights and biases
void initialize(NeuralNetwork* nn) {
    nn->weight = ((double)rand() / RAND_MAX) * 2 - 1;
    nn->bias = ((double)rand() / RAND_MAX) * 2 - 1;
}

// Forward pass through the neural network
double forward(NeuralNetwork* nn, double input) {
    return linear(nn->weight * input + nn->bias);
}

int main() {
    srand(42); // Seed for reproducibility

    // Training data
    double celsius[] = {-40, -10, 0, 8, 15, 22, 38};
    double fahrenheit[] = {-40, 14, 32, 46.4, 59, 71.6, 100.4};

    // Normalize training data
    double minCelsius = -40.0;
    double maxCelsius = 38.0;
    double minFahrenheit = -40.0;
    double maxFahrenheit = 100.4;

    for (int i = 0; i < 7; i++) {
        celsius[i] = normalize(celsius[i], minCelsius, maxCelsius);
        fahrenheit[i] = normalize(fahrenheit[i], minFahrenheit, maxFahrenheit);
    }

    // Training parameters
    double learningRate = 0.001;
    int epochs = 10000;

    NeuralNetwork nn;
    initialize(&nn);

    // Training loop
    for (int epoch = 0; epoch < epochs; epoch++) {
        for (int i = 0; i < 7; i++) {
            double input = celsius[i];
            double label = fahrenheit[i];

            // Forward pass
            double output = forward(&nn, input);

            // Backpropagation
            double error = label - output;
            double outputGradient = error;

            // Update weights and bias
            nn.weight += learningRate * outputGradient * input;
            nn.bias += learningRate * outputGradient;
        }
    }

    // Test the trained neural network
    printf("\nTesting the trained neural network...\n");
    printf("Celsius | Predicted Fahrenheit\n");
    printf("-----------------------------\n");
    for (int i = 0; i < 7; i++) {
        double input = celsius[i];
        double prediction = denormalize(forward(&nn, input), minFahrenheit, maxFahrenheit);

        printf("%.1f    | %.1f\n", denormalize(input, minCelsius, maxCelsius), prediction);
    }

    return 0;
}
