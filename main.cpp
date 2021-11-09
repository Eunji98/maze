#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


vector<int> ans_x;
vector<int> ans_y;
int start_x = 0;
int start_y = 0;
int end_x = 0;
int end_y = 0;
int** maze;
int row;
int col;
int dx[4] = {1, 0, -1,0 };
int dy[4] = {0, 1, 0,-1};



int inside(int x, int y) {
	if (0 <= x < row && 0 <= y < col)
		return 1;
	return 0;
}


void print_sol() {
	for (int i = 0;i < ans_x.size();i++) {
		cout << ans_x[i] << ',' << ans_y[i] << endl;
	}
	return;
	
}

//dir = 0 when towards south, 1: east, 2 : north, 3 : west
void solve_maze(int x, int y, int dir) {
	
	if (maze[x][y] == 1) {
		//cout << x << y << endl;
		ans_x.push_back(x);
		ans_y.push_back(y);
	}
	else
		return;

	if (x == end_x && y == end_y) {
		cout << endl << "maze solved!" << endl;
		return;
	}

	//priority as turn right, go straight, turn left, backward
	for (int i = 3;i < 7 ;i++) {
		int new_x = x + dx[(dir+i)%4];
		int new_y = y + dy[(dir + i) % 4];
		if (inside(new_x, new_y) && maze[new_x][new_y] == 1) {
			cout << new_x << new_y << (dir + i) % 4<< endl;
			solve_maze(new_x, new_y, (dir+i)%4);
			break;
		}

	}
	
	return;

}

void print_maze() {
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			cout << maze[i][j];
		}
		cout << endl;
	}
}


int main() {

	int num; // number of roads

	cin >> row;
	cin >> col;
	cin >> num;
	//cout << row << endl << col << endl << num << endl;

	//making maze with dynamic allocation
	maze = (int**)malloc(sizeof(int*) * row);
	visited = (int**)malloc(sizeof(int*) * row);
	for (int i = 0;i < row;i++) {
		maze[i] = (int*)malloc(sizeof(int) * col);
		visited[i] = (int*)malloc(sizeof(int) * col);
		for (int j = 0;j < col;j++) {
			maze[i][j] = 0;
			visited[i][j] = 0;
		}
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

		if (i == 0) {
			start_x = stoi(arr[0]);
			start_y = stoi(arr[1]);
		}
		if (i == num - 1) {
			end_x = stoi(arr[0]);
			end_y = stoi(arr[1]);
		}
		
		maze[stoi(arr[0])][stoi(arr[1])] = 1;

		//clear vector memory
		arr.clear();
		arr.shrink_to_fit();
		//cout << arr.size() << arr.capacity();
	}

	//print maze
	print_maze();

	//solve maze
	solve_maze(start_x, start_y,1);

	print_sol();
	

	return 0;
}

