#pragma once

#include <iostream>

#define MAX_VEX 100
#define NIL -1
using namespace std;

//�߽ڵ�
struct EdgeNode
{
	int adjvex;				//�����±�
	struct EdgeNode* next;	//ָ����һ���ߵ�ָ��
};

//����ڵ�
struct VertexNode
{
	int val;				//�����ֵ
	EdgeNode* firstEdge;	//��һ����
};

//����ͼ
class Graph
{
public:
	Graph();
	//Graph(const Graph& other);
	~Graph();
	int addNode(int val);						//��ӽڵ�
	bool addEdge(int index1, int index2);			//��ӱ�
	bool editNode(int n, int newval);			//�޸Ľڵ�
	//bool deleteNode(int val);					//ɾ���ڵ�
	//bool deleteEdge(int val1, int val2);		//ɾ����

	int searchPoint(int n);//ͨ��valֵ���ҵ���±�

	void articuPointUtil(int u, bool visited[], int depth[], int low[], int parent[],int curDepth, bool articuPoints[]);	//DFS���ҹؽڵ�
	void searchArticuPoint();		//���ҹؽڵ�
	void displayArticuPoint();		//����ؽڵ�
	void articulareModify(int n);	//�˺������ڽ��ؽڵ�ת��Ϊ�ǹؽڵ�
	void clear();					//���ͼ
	void printGrgph();             //���ͼ
	int valRetrun(int n);
private:
	VertexNode vertexNodes[MAX_VEX];	//��������
	int numNodes;						//ͼ����������
	int numEdges;						//ͼ�����ߵ�����
	bool articuPoints[MAX_VEX];			//�Ƿ�Ϊ�ؽڵ�

	friend class Add;

};
