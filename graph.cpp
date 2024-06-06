/*
	Title: graph.cpp
	Author: Cole Howell
	Purpose: Demonstrate graph and depth first-search implementation
*/

#include "graphMatrix.h"
#include "graphList.h"
#include "Stack.h"
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream inFile;
	string filename;
	int size;
	
	cout << "Enter the file name that contains the appropriate graph vertices: ";
	do{
		getline(cin, filename);
		inFile.open(filename.c_str());
		
		if(!inFile.good()){
			cout << "This file does not exist.\n";
			cout << "Enter a new file name: ";
		}
		
	}while (!inFile.good());
	
	inFile >> size;

	graphList g = graphList(size); //create graph list object
	graphMatrix m = graphMatrix(size); //create graph matrix object
	
	if(inFile){
		int v1, v2; //variables for the vertices while reading them from file
	
		while(inFile >> v1){
			inFile >> v2;
			g.addEdge(v1, v2);
			m.addEdge(v1, v2);
		}
	}
	
	inFile.close();
	g.printGraph();
	m.printGraph();
	
	Stack<int> dfs_stack = Stack<int>();
	bool* visited = new bool[size];
	int currentVertex = 0; //current home
	visited[0] = true;
	cout << "\nDepth First Search\n\n";
	
	dfs_stack.push(currentVertex);
	cout << currentVertex << "\t";
	
	while (!dfs_stack.isEmpty()){
		dfs_stack.peek(currentVertex);
		
		if(!visited[currentVertex]){
			visited[currentVertex] = true;
		}
		int i = 1;
		bool startOver;
		for(int i = 0; i<size; i++){
			if (startOver){
				i = 0;
				startOver = false;
			}
			if (m.isThereAnEdge(currentVertex, i) && !visited[i]){
				currentVertex = i;
				dfs_stack.push(currentVertex);
				visited[currentVertex] = true;
				cout << currentVertex << "\t";
				startOver = true;
			}
		}
		dfs_stack.pop(currentVertex);
	}
	return 0;
}