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
	bool randomInput(int minNodes, int maxNodes, int maxEdges); // ������뺯������
	bool isConnected();  // �������ж�ͼ��ͨ�Եĺ�������	
	Graph g;
};