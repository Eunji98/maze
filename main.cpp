#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int main() {
	int row, col;
	int **maze;
	int num; // number of roads

	cin >> row;
	cin >> col;
	cin >> num;
	cout << row << endl << col << endl << num << endl;

	//making maze with dynamic allocation
	maze = (int**)malloc(sizeof(int*) * row);
	for (int i = 0;i < row;i++) {
		maze[i] = (int*)malloc(sizeof(int) * col);
		for (int j = 0;j < col;j++)
			maze[i][j] = 0;
	}


	for (int i = 0;i < num;i++) {
		
		string road;
		vector<string> arr;
		string buffer;
		int x, y;

		cin >> road;
		istringstream ss(road);
		
		while (getline(ss, buffer, ',')) {
			arr.push_back(buffer);
		}
		
		maze[stoi(arr[0])][stoi(arr[1])] = 1;

		//clear vector memory
		arr.clear();
		arr.shrink_to_fit();
		cout << arr.size() << arr.capacity();
	}


	//print maze
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			cout << maze[i][j];
		}
	}

	//cout << maze;
	return 0;
}