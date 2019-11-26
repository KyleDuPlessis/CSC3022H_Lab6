//=================================================================================
// Name        : Perceptron.cpp
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 01/10/2019
// Description : An algorithm that uses only perceptrons with threshold
//				 activation functions and the perceptron learning rule
//				 (chapter 4 [Mitchell, 1997]) to solve the binary A XOR B problem
//				 - written in C++, Ansi-style
//=================================================================================

#include "Perceptron.h"

int DPLKYL002::Perceptron::generatePerceptron(float x1, float x2) {

	float sumX = (x1 * constantWeights[0]) + (x2 * constantWeights[1])
			+ constantWeights[2];

	return ((sumX > constantThreshold) ? 1 : 0);

}

int DPLKYL002::TrainingExample::generateXOR(float x1, float x2,
		DPLKYL002::Perceptron logicAND, DPLKYL002::Perceptron logicOR,
		DPLKYL002::Perceptron logicNAND) {

	int outputNAND = logicNAND.generatePerceptron(x1, x2);

	int outputOR = logicOR.generatePerceptron(x1, x2);

	return logicAND.generatePerceptron(outputNAND, outputOR);

}

void DPLKYL002::Perceptron::perceptronTrain(int numIterations,
		float learningRate) {

	ofstream outputFile = ofstream("answers.txt", ios_base::app);

	for (int k = 0; k < numIterations; ++k) {

		int numErrors = 0;

		for (auto example : vectTrainingExamples) {

			float x1 = example[0];

			float x2 = example[1];

			int targetOutput = (int) example[2];

			int output = 0;

			float sumX = (x1 * constantWeights[0]) + (x2 * constantWeights[1])
					+ (1 * constantWeights[2]);

			if (sumX > constantThreshold) {

				output = 1;

			}

			if (output != targetOutput) {

				numErrors += 1;

				constantWeights[0] += learningRate * (targetOutput - output)
						* x1;

				constantWeights[1] += learningRate * (targetOutput - output)
						* x2;

				constantWeights[2] += learningRate * (targetOutput - output)
						* 1;

			}

		}

		if (numErrors == 0) {

			outputFile << "Number of iterations: " << k + 1 << endl;

			break;

		}

	}

	outputFile.close();

}

vector<vector<float>> DPLKYL002::processTrainingExamples(string fileName) {

	ifstream iFile(fileName);

	vector<vector<float>> vectTrainingExamples;

	ofstream outputFile = ofstream("answers.txt", ios_base::app);

	if (iFile.is_open()) {

		string input;

		while (getline(iFile, input)) {

			stringstream ss(input);

			vector<float> vectElements;

			for (int k = 0; k < 3; ++k) {

				float element;

				ss >> element;

				vectElements.push_back(element);

			}

			vectTrainingExamples.push_back(vectElements);

		}

	} else {

		outputFile << "Error - unable to open file: " << fileName << endl;

	}

	iFile.close();

	outputFile.close();

	return vectTrainingExamples;

}

DPLKYL002::Perceptron DPLKYL002::TrainingExample::train(string fileName,
		int numIterations, float learningRate) {

	ofstream outputFile = ofstream("answers.txt", ios_base::app);

	DPLKYL002::Perceptron p(processTrainingExamples(fileName + ".txt"));

	outputFile << fileName << " logic: " << endl;

	p.perceptronTrain(numIterations, learningRate);

	outputFile << "Weight 1: " << p.constantWeights[0] << endl;

	outputFile << "Weight 2: " << p.constantWeights[1] << endl;

	outputFile << "Weight 3: " << p.constantWeights[2] << endl;

	int x1, x2;

	x1 = 0;

	x2 = 0;

	outputFile << x1 << " " << x2 << " " << p.generatePerceptron(x1, x2)
			<< endl;

	x1 = 1;

	x2 = 0;

	outputFile << x1 << " " << x2 << " " << p.generatePerceptron(x1, x2)
			<< endl;

	x1 = 0;

	x2 = 1;

	outputFile << x1 << " " << x2 << " " << p.generatePerceptron(x1, x2)
			<< endl;

	x1 = 1;

	x2 = 1;

	outputFile << x1 << " " << x2 << " " << p.generatePerceptron(x1, x2)
			<< endl;

	outputFile.close();

	return p;

}

