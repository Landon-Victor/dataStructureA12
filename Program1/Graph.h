#pragma once

#include <iostream>

#define MAX_VEX 100
#define NIL -1
using namespace std;

//边节点
struct EdgeNode
{
	int adjvex;				//顶点下标
	struct EdgeNode* next;	//指向下一条边的指针
};

//顶点节点
struct VertexNode
{
	int val;				//顶点的值
	EdgeNode* firstEdge;	//第一条边
};

//无向图
class Graph
{
public:
	Graph();
	//Graph(const Graph& other);
	~Graph();
	int addNode(int val);						//添加节点
	bool addEdge(int index1, int index2);			//添加边
	bool editNode(int n, int newval);			//修改节点
	//bool deleteNode(int val);					//删除节点
	//bool deleteEdge(int val1, int val2);		//删除边

	int searchPoint(int n);//通过val值查找点的下标

	void articuPointUtil(int u, bool visited[], int depth[], int low[], int parent[],int curDepth, bool articuPoints[]);	//DFS查找关节点
	void searchArticuPoint();		//查找关节点
	void displayArticuPoint();		//输出关节点
	void articulareModify(int n);	//此函数用于将关节点转换为非关节点
	void clear();					//清空图
	void printGrgph();             //输出图
	int valRetrun(int n);
private:
	VertexNode vertexNodes[MAX_VEX];	//顶点数组
	int numNodes;						//图所含顶点数
	int numEdges;						//图所含边的数量
	bool articuPoints[MAX_VEX];			//是否为关节点

	friend class Add;

};
