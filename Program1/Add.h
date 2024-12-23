#pragma once
#include<iostream>
#include"Graph.h"
using namespace std;
class Add
{
public:
	Add(const Graph&g);
	~Add();
	void display();
	bool loadFromFile(const string& filename);		//从文件读取数据
	void saveToFile(const string& filename) const;	//保存数据到文件
	void inputGraph();	//人工读入数据
	
	Graph g;
};