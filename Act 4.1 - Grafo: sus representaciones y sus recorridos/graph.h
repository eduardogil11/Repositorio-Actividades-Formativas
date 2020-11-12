 /*
 * graph.h
 *
 *  Created on: 12/11/2020
 *      Author: Eduardo Rodríguez Gil
 */

#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string print_vector(vector<int> vec) {
	string result = "";
	for (int i=0; i<vec.size(); i++) {
		result = result + to_string(vec[i]) + " ";
	}
	return result;
}

class Graph {
	private:
	int ma_vertex;
	int ma_rim;
  vector<vector<int>> add_matrix;
	vector<vector<int>> add_list;

	public:
	Graph() {}
	string printAdjMat();
	string printAdjList();
  void loadGraphMat(string filename, int vertex, int rim);
	void loadGraphList(string filename, int vertex, int rim);
	string DFS(int into_vert, int end_vert);
	string BFS(int into_vert, int end_vert);
};

string Graph::printAdjMat() {
	string result = "";
	for(int i=0; i<add_matrix.size(); i++) {
		for(int j=0; j<add_matrix[i].size(); j++) {
			result = result + to_string(add_matrix[i][j]) + " ";
		}
	}
	return result;
}

string Graph::printAdjList() {
	string result = "";
	for(int i=0; i<add_list.size(); i++) {
		result += "vertex " + to_string(i) + " : ";
		sort(add_list[i].begin(), add_list[i].end());
		for(int j=0; j<add_list[i].size(); j++){
			result += to_string(add_list[i][j]) + " ";
		}
	}
	return result;
}

void Graph::loadGraphMat(string filename, int vertex, int rim) {
	ma_rim = rim;
	ma_vertex = vertex;
	for (int i=0; i<vertex; i++) {
		vector<int> row(vertex, 0);
		add_matrix.push_back(row);
	}
	ifstream file;
	file.open(filename);
	while(file.good()) {
		string into_vert; 
		string end_vert;
		getline(file, into_vert, ',');
		getline(file, end_vert, '\n');
		into_vert = into_vert.substr(1, into_vert.length()-1);
		end_vert = end_vert.substr(1, end_vert.length()-2);
		int into_node = stoi(into_vert);
		int end_node = stoi(end_vert);
		add_matrix[into_node][end_node] = 1;
		add_matrix[end_node][into_node] = 1;
	}
}

void Graph::loadGraphList(string filename, int vertex, int rim) {
	ma_vertex = vertex;
	ma_rim= rim;
	for (int i=0; i<vertex; i++) {
		vector<int> row;
		add_list.push_back(row);
	}
	ifstream file;
	file.open(filename);
	while(file.good()) {
		string into_vert;
		string end_vert;
		getline(file, into_vert, ',');
		getline(file, end_vert, '\n');
		into_vert = into_vert.substr(1, into_vert.length()-1);
		end_vert = end_vert.substr(1, end_vert.length()-2);
		int into_node = stoi(into_vert);
		int end_node = stoi(end_vert);
		add_list[into_node].push_back(end_node);
		add_list[end_node].push_back(into_node);
	}
}

string Graph::DFS(int into_vert, int end_vert) {
	vector<vector<int>> add_list_copy;
	for (int i=0; i<add_list.size(); i++) {
		add_list_copy.push_back(add_list[i]);
	}
	vector<int> stack;
	vector<int> visited;
	bool found = false;
	int current = into_vert;
	while (!found && !(visited.size() >= ma_vertex)) {
		bool already_visited = false;
		for (int i=0; i<visited.size(); i++) {
			if(current == visited[i]) {
				already_visited = true;
				break;
			}
		}
		if (!already_visited) visited.push_back(current);
		if (current == end_vert) {
			found = true;
			break;
		}
		for (int i=0; i<add_list_copy[current].size(); i++) {
			for (int j=0; j<visited.size(); j++) {
				if(add_list_copy[current][i] == visited[j])
					add_list_copy[current].erase(add_list_copy[current].begin()+i);
			}
		}
		if (add_list_copy[current].size() > 0) {
			stack.push_back(current);
			int temp_index = current;
			current = add_list_copy[current].back();
			add_list_copy[temp_index].pop_back();
		} 
		else {
			current = stack[stack.size()-1];
			stack.pop_back();
		}
	}
	stack.push_back(current);
	string visited_str = print_vector(visited);
	string path_str = print_vector(stack);
	string result = "visited: " + visited_str + "path: " + path_str;
	result = result.substr(0, result.size()-1);
	return result;
}

string Graph::BFS(int into_vert, int end_vert) {
	vector<vector<int>> queue;
	vector<vector<int>> visited;
	int current = into_vert;
	int parent = -1;
	bool found = false;
	while (true) {
		visited.push_back(vector<int>({parent, current}));
		if (current == end_vert) {
			found = true;
			break;
		}
		for (int i=0; i<add_list[current].size(); i++) {
			int val = add_list[current][i];
			bool already_visited = false;
			for (int j=0; j<visited.size(); j++) {
				if (visited[j][1] == val) {
					already_visited = true;
					break;
				}
			}
			if (!already_visited) queue.push_back(vector<int>({current, val}));
		}
		parent = queue[0][0];
		current = queue[0][1];
		queue.erase(queue.begin());
	}
	vector<int> path;
	int find = end_vert;
	do {
		for (int i=0; i<visited.size(); i++) {
			if (visited[i][1] == find) {
				path.insert(path.begin(), find);
				find = visited[i][0];
			}
		}
	} while (find != -1);
	vector<int> converted_visited;
	for (int i=0; i<visited.size(); i++) {
		converted_visited.push_back(visited[i][1]);
	}
	string visited_str = print_vector(converted_visited);
	string path_str = print_vector(path);
	string result = "visited: " + visited_str + "path: " + path_str;
	result = result.substr(0, result.size()-1);
	return result;	
}