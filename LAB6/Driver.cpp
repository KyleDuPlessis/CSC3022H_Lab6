//=================================================================================
// Name        : Driver.cpp
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 01/10/2019
// Description : An algorithm that uses only perceptrons with threshold
//				 activation functions and the perceptron learning rule
//				 (chapter 4 [Mitchell, 1997]) to solve the binary A XOR B problem
//				 - written in C++, Ansi-style
//=================================================================================

#include "Perceptron.h"

// main function
int main(int argc, char * argv[]) { // argc and argv values passed into main

	ofstream outputFile = ofstream("answers.txt");

	outputFile << "Applying the algorithm that uses only perceptrons:" << endl
			<< endl;

	outputFile.close();

	// initialisation

	DPLKYL002::TrainingExample te;

	DPLKYL002::Perceptron perceptronAND = te.train("AND", 1000, 0.1);

	outputFile = ofstream("answers.txt", ios_base::app);

	outputFile << endl;

	outputFile.close();

	DPLKYL002::Perceptron perceptronOR = te.train("OR", 1000, 0.1);

	outputFile = ofstream("answers.txt", ios_base::app);

	outputFile << endl;

	outputFile.close();

	DPLKYL002::Perceptron perceptronNAND = te.train("NAND", 1000, 0.1);

	outputFile = ofstream("answers.txt", ios_base::app);

	outputFile << endl;

	outputFile << "All perceptrons trained successfully." << endl << endl;

	outputFile << "XOR logic: " << endl;

	ifstream iFile("XOR.txt");

	if (iFile.is_open()) {

		string input;

		while (getline(iFile, input)) {

			stringstream ss(input);

			vector<float> vectElements;

			for (int k = 0; k < 2; ++k) {

				float element;

				ss >> element;

				vectElements.push_back(element);

			}

			outputFile << vectElements[0] << " " << vectElements[1] << " "
					<< te.generateXOR(vectElements[0], vectElements[1],
							perceptronAND, perceptronOR, perceptronNAND)
					<< endl;

		}

	} else {

		outputFile << "Error - unable to open file: XOR.txt" << endl;

	}

	outputFile << endl;

	outputFile << "Question 1:"
			"\nThe minimum number of perceptrons required to solve the XOR problem is 3."
			"\nSince the XOR logic gate can be implemented as a combination of OR, NAND and AND logic gates, "
			"\nthe logic equation can be written as follows:"
			"\nA XOR B = (A OR B) AND (A NAND B)"
			"\nThe perceptrons should be connected in two layers with the outputs of the first layer "
			"\nfeeding into the inputs of the second layer as shown visually below:"
			"\n\nPERCEPTRON OR--------------\\\\
             		   \n\t\t\t\t\t\t\tPERCEPTRON AND------------>XOR OUTPUT"
			"\nPERCEPTRON NAND------------/"
			"\n\nQuestion 2:"
			"\n12 training examples altogether (i.e. 4 for each logic gate found in AND.txt, OR.txt and NAND.txt)." << endl;

	iFile.close();

	outputFile.close();

	cout << "answers.txt written successfully" << endl;

	return 0;

}

