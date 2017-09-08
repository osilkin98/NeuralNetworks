#include <vector>
#include <iostream>
#include "neuron.h"

using namespace std;

void print_matrix(vector< vector<int> > const mat) {
	for(int i = 0; i < mat.size(); ++i) {
		cout << "\t\t[";
		for(int j = 0; j < mat[i].size(); ++j) {
			cout << " " << mat[i][j] << " ";
		}
		cout << "]" << endl;
	}
}

void test_matrix(vector< vector<int> > const matrix) {
	
	vector<Neuron_mid> mid; 
	for(int i = 0; i < matrix.size(); ++i) {
		vector<Neuron_hidden> elems;
		for(int j = 0; j < matrix[i].size(); ++j) {
			elems.push_back(Neuron_hidden( matrix[i][j] ));
		}
		mid.push_back( elems );
	}
	Neuron_Main mn = Neuron_Main( mid );
	
	cout << endl;
	
	print_matrix(matrix);
	
	cout << endl;
	
	if(mn.is_line()) {
		cout << "This matrix has one or more straight lines in horizontal orientation!";
	} else {
		cout << "This matrix does NOT have a straight line in horizontal orientation.";
	}
	
	cout << endl;
}

int main() {
	/*
  
  vector< vector<int> > matrix1 = { 
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{1, 1, 1, 1, 1},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
	};
	vector< vector<int> > matrix2 = { 
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{1, 1, 1, 0, 1},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
	};
	vector< vector<int> > matrix3 = { 
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
	};
	vector< vector<int> > matrix4 = { 
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1}
	};
	vector< vector<int> > matrix5 = { 
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1},
			{0, 0, 0, 0, 0},
			{1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1}
	};
	
	
	
	test_matrix(matrix1);
	test_matrix(matrix2);
	test_matrix(matrix3);
	test_matrix(matrix4);
	test_matrix(matrix5);
	*/
	
	return 0;
}
