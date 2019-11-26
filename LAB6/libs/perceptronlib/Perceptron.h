//=================================================================================
// Name        : Perceptron.h
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 01/10/2019
// Description : An algorithm that uses only perceptrons with threshold
//				 activation functions and the perceptron learning rule
//				 (chapter 4 [Mitchell, 1997]) to solve the binary A XOR B problem
//				 - written in C++, Ansi-style
//=================================================================================

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#ifndef LIBS_PERCEPTRON_H
#define LIBS_PERCEPTRON_H

using namespace std;

namespace DPLKYL002 {

class Perceptron {

private:

	// private members
	vector<vector<float>> vectTrainingExamples;

	int constantThreshold;

public:

	// public members
	vector<float> constantWeights;

	Perceptron(vector<vector<float>> v) :
			constantThreshold(1), constantWeights(3, 0.0F) {

		this->vectTrainingExamples.resize(v.size());

		for (int k = 0; k < v.size(); ++k) {

			this->vectTrainingExamples[k] = move(v[k]);

		}

	}

	int generatePerceptron(float x1, float x2);

	void perceptronTrain(int numIterations, float learningRate);

};

class TrainingExample {

public:

	// public members
	DPLKYL002::Perceptron train(string fileName, int numIterations,
			float learningRate);
	int generateXOR(float x1, float x2, DPLKYL002::Perceptron logicAND,
			DPLKYL002::Perceptron logicOR, DPLKYL002::Perceptron logicNAND);

};

vector<vector<float>> processTrainingExamples(string fileName);

}

#endif
