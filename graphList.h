/*
	Title: graphList.h
	Author: Cole Howell
	Purpose: Class implementation of a graph
*/

#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <iostream>

using namespace std;

class graphList{
	
	private:
		struct ListNode{
			int value;
			ListNode* next;
		};
		ListNode** headArray;
		int numVertices;
		int numEdges;
		
	public:
		graphList(int numV){
			numVertices = numV;
			headArray = new ListNode*[numV];
			for (int i=0; i < numV; i++){
				headArray[i] = NULL;
			}
		}
	
		~graphList(){
			for (int i = 0; i<numVertices; i++){
				delete headArray[i];
			}
			delete []headArray;
		}
	
		void addEdge(int v1, int v2){
			
			//make new node for the second value entered, this represents the adjacent node to the root
			ListNode* newNode = new ListNode;
			newNode->value = v2;
			newNode->next = NULL;
			numEdges++;
			
			//creating temp list node pointer
			ListNode* temp = headArray[v1];
			
			//two cases for storing values into the headArray
			if (temp == NULL){
				headArray[v1] = newNode;
			}
			else{ //if there is already an edge connected to v1 then v2 will be put at at the end of 
				while (temp->next != NULL){
					temp = temp->next;
				}
				temp->next = newNode;
			}
			cout << "Adding an edge from " << v1 << " to " << v2 << ".\n";
		}

		void printGraph(){
			cout << "\n\nAdjacency List\n";
			ListNode* temp;
			for(int i=0; i<numVertices; i++){
				cout << i;
				
				temp = headArray[i];
				while(temp != NULL){ //will print the connected vertices like a hash table would be printed
					cout << "---->" << temp->value;
					temp = temp->next;
				}
				cout << "---->NULL\n";
			}	
		}
};

#endif