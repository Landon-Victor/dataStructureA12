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
	bool loadFromFile(const string& filename);		//���ļ���ȡ����
	void saveToFile(const string& filename) const;	//�������ݵ��ļ�
	void inputGraph();	//�˹���������
	
	Graph g;
};