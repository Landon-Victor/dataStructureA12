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
	bool randomInput(int minNodes, int maxNodes, int maxEdges); // 随机输入函数声明
	bool isConnected();  // 新增的判断图连通性的函数声明	
	Graph g;
};