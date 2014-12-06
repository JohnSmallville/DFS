// DFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef int Vertex;

typedef std::vector < std::list < int > > Graph;

Graph graph;

#define inf 0x7FFFFFFF //~бесконечность для int

std::vector <Vertex> color;// 0 == white; 1 == gray; 2 == black;
std::vector <int> pred;
std::vector <int> d;
int time = 0;

void DFS_Visit(Vertex);
void DFS(Vertex vertex) {
	
	std::queue <Vertex> Q;

	color.resize(graph.size());
	pred.resize(graph.size());
	d.resize(graph.size());


	for (int i = 0; i < graph.size(); ++i) {
		color[i] = 0; //white
		pred[i] = 0;
	}

	for (int i = 0; i < graph.size(); ++i) {
		if (!color[i]) {
			DFS_Visit(i);
		}
	}
}

void DFS_Visit(Vertex vertex) {

	color[vertex] = 1;
	time++;
	d[vertex] = time;

	for (std::list<int>::iterator it = graph[vertex].begin(); it != graph[vertex].end(); it++) {
		if (!color[*it]) {
			color[*it] = 1;
			pred[*it] = vertex;
			DFS_Visit(*it);
			std::cout << *it << ' ';
		}
	}
	getchar();
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream ifstr("input.txt");
	int v_num, e_num;
	ifstr >> v_num >> e_num; // количество вершин, количество ребер с весом (откуда, куда)
	graph.resize(v_num);
	for (int i = 0; i < e_num; ++i) {
		int from_vertex, to_vertex;
		ifstr >> from_vertex >> to_vertex;
		graph[from_vertex].push_back(to_vertex);
	}

	DFS(0);

	getchar();
	return 0;
}

