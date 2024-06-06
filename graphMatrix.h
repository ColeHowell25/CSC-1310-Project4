/*
	Title: graphMatrix.h
	Author: Cole Howell
	Purpose: Code for a graph matrix object

*/

#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

#include <iostream>

using namespace std;

class graphMatrix{
	private:
		int** vertexMatrix;
		int numVertices;
		int numEdges;
	
	public:
		graphMatrix(int numV){
			numVertices = numV;
			vertexMatrix = new int*[numV]; //since this is a matrix, a 2D array is required 
			for(int i=0; i<numV; i++){
				vertexMatrix[i] = new int[numV];
			}
			
			for (int i = 0; i<numV; i++){ //nested for loop sets all values within the matrix to 0
				for (int j=0; j<numV; j++){
					vertexMatrix[i][j] = 0;
				}
			}
		}
	
		~graphMatrix(){
			for (int i = 0; i<numVertices; i++){ //nested for loop deletes all that's inside the matrix and the matrix
				delete[] vertexMatrix[i];
			}
			delete []vertexMatrix;
		}
	
		void addEdge(int v1, int v2){
			vertexMatrix[v1][v2] = 1;
		}
		
		void printGraph(){
			cout << "\n\nPrinting Adjacency Matrix\n"; 
			for (int i = 0; i<numVertices; i++){ //nested for loop prints all values within the matrix
				for (int j=0; j<numVertices; j++){
					cout << vertexMatrix[i][j] << "\t";
				}
				cout << endl;
			}
			
		}

		bool isThereAnEdge(int row, int column){
			if (vertexMatrix[row][column] == 1){ //if the matrix is equal to 1 at the pos then there is an edge
				return true;
			}
			else{
				return false;
			}
		}
};
#endif