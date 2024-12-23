#include"Graph.h"

Graph::Graph()
{
	for (int i = 0; i < MAX_VEX; i++)
	{
		vertexNodes[i].val = 0;
		vertexNodes[i].firstEdge = NULL;
		articuPoints[i] = false;
	}
	numEdges = 0;
	numNodes = 0;
}
//Graph::Graph(const Graph& other)
//{
//	numEdges = other.numEdges;
//	numNodes = other.numNodes;
//	for (int i = 0; i < numNodes; i++)
//	{
//		vertexNodes[i] = other.vertexNodes[i];
//		articuPoints[i] = other.articuPoints[i];
//
//	}
//}
Graph::~Graph()
{

}
void Graph::printGrgph()
{
	for (int i = 0; i < numNodes; i++)
	{
		cout << "第" << i + 1 << "个结点" << "值为：" << vertexNodes[i].val << "其相邻的结点有：";
		EdgeNode*temp = vertexNodes[i].firstEdge;
		while (temp)
		{
			cout << temp->adjvex << " ";
			temp = temp->next;
		}
		cout << "\n";
	 }
}
int Graph::valRetrun(int n)
{
	return vertexNodes[n-1].val;
}
//添加节点
int Graph::addNode(int val) {
	if (numNodes < MAX_VEX) {
		vertexNodes[numNodes].val = val;
		vertexNodes[numNodes].firstEdge = NULL;
		numNodes++;
		return numNodes - 1;
	}
	else {
		cout << "节点数量超出限制" << endl;
	}
}

//添加边
bool Graph::addEdge(int index1, int index2) {
	if (index1<0||index1>numNodes) 
	{
		cout <<" 结点一不存在\n";
		return false;
	}
	if (index2<0 || index2>numNodes)
	{
		cout << "结点二不存在\n";
		return false;
	}
	if (index1==index2) 
	{
		cout << "边两端节点不能相同\n";
		return false;
	}
	EdgeNode* temp = vertexNodes[index1-1].firstEdge;
	while (temp)
	{
		if (temp->adjvex == index2)
		{
			cout << "该边已存在\n";
			return false;
		}
		temp = temp->next;
	}
	temp = vertexNodes[index2].firstEdge;
	EdgeNode* newEdge1 = new EdgeNode;
	newEdge1->adjvex = index2; 
	newEdge1->next = vertexNodes[index1].firstEdge; 
	vertexNodes[index1].firstEdge = newEdge1;
	EdgeNode* newEdge2 = new EdgeNode;
	newEdge2->adjvex = index1; 
	newEdge2->next = vertexNodes[index2].firstEdge; 
	vertexNodes[index2].firstEdge = newEdge2;
	numEdges++;
	cout << "边 (" << index1 << ", " << index2 << ") 添加成功！\n";
	return true;
}
//通过val值查找节点的角标
int Graph::searchPoint(int val)
{
	for (int i = 0; i < numNodes; i++) 
	{
		if (vertexNodes[i].val == val)return i;
	}
	return -1;
}
//修改val为n的节点的val为newval
bool Graph::editNode(int n, int newval)
{
	if (n<=numNodes&&n>0) {
		vertexNodes[n].val = newval;
		cout << "修改成功\n";
		return true;
	}
	else
	{
		cout << "该节点不在图中，请重新输入\n";
		return false;
	}
}

//删除边
//bool Graph::deleteEdge(int val1, int val2) 
//{ 
//	bool flag = false;
//	int index1 = searchPoint(val1);
//	int index2 = searchPoint(val2);
//	if (index1 == -1)
//	{
//		cout << "值为 " << val1 << " 的节点不存在！\n";
//		return false;
//	}
//	if (index2 == -1)
//	{
//		cout << "值为 " << val2 << " 的节点不存在！\n";
//		return false;
//	}
//	//删除val1中的边
//	EdgeNode* temp = vertexNodes[index1].firstEdge;
//	EdgeNode* temp1 = temp;
//	if (temp == nullptr)
//	{
//		cout << "想要删除的边不存在\n";
//		return false;
//	}
//	if (temp->adjvex == index2)
//	{
//		vertexNodes[index1].firstEdge = temp->next;
//		flag = true;
//	}
//	while (temp != nullptr && !flag)
//	{
//		if (temp->adjvex == index2)
//		{
//			temp1->next = temp->next;
//			flag = true;
//			break;
//		}
//		temp1 = temp;
//		temp = temp->next;
//	}
//	if (!flag)
//	{
//		cout << "想要删除的边不存在\n";
//		return false;
//	}
//	//删除val2中的边
//	flag = false;
//    temp = vertexNodes[index2].firstEdge;
//    temp1 = temp;
//	if (temp->adjvex == index1)
//	{
//		vertexNodes[index2].firstEdge = temp->next;
//		flag = true;
//	}
//	while (temp != nullptr && !flag)
//	{
//		if (temp->adjvex == index2)
//		{
//			temp1->next = temp->next;
//			break;
//		}
//		temp1 = temp;
//		temp = temp->next;
//	}
//	--numEdges;
//	cout << "值为" << val1 << "的结点到值为" << val2 << "的结点的边已被删除\n";
//	return true;
//}
//
////删除节点
//bool Graph::deleteNode(int val)
//{
//	int index = searchPoint(val);
//	if (index == -1)
//	{
//		cout << "值为 " << val << " 的节点不存在！\n";
//		return false;
//	}
//	while (vertexNodes[index].firstEdge != nullptr)
//	{
//		deleteEdge(vertexNodes[vertexNodes[index].firstEdge->adjvex].val,val);
//	}
//	for (int i = index;i <= numNodes - 2;i++)
//	{
//		vertexNodes[i] = vertexNodes[i + 1];
//	}
//	--numNodes;
//	EdgeNode* temp;
//	for (int i = 0;i <= numNodes - 1;i++)
//	{
//		temp = vertexNodes[i].firstEdge;
//		while (temp != nullptr)
//		{
//			if (temp->adjvex > index) {
//				--temp->adjvex;
//			}
//			temp = temp->next;
//		}
//	}
//	cout << "值为" << val << "的结点已被删除\n";
//	return true;
//}

//DFS_确认图为连通图
void Graph::dfsConnected(int u, int& counts, bool visited[])
{
	++counts;
	visited[u] = true;
	int v;
	EdgeNode* temp = vertexNodes[u].firstEdge;
	while (temp != nullptr)
	{
		v = temp->adjvex;
		if (visited[v]) {}
		else {
			dfsConnected(v, counts, visited);
		}
		temp = temp->next;
	}
}

//确认图为连通图
bool Graph::isConnected()
{
	int counts = 0;
	bool* visited = new bool[numNodes];
	for (int i = 0;i <= numNodes - 1;i++)
		visited[i] = false;
	dfsConnected(0, counts, visited);
	delete visited;
	if (counts == numNodes) {
		return true;
	}
	cout << "您输入的不是连通图！！！\n";
	return false;
}

//DFS查找关节点
void Graph::articuPointUtil(int u, bool visited[], int depth[], int low[], int parent[], int curDepth, bool articuPoints[])
{
	visited[u] = true;
	int children = 0;
	depth[u] = low[u] = curDepth;
	EdgeNode* it = vertexNodes[u].firstEdge;
	for (; it != NULL; it = it->next)
	{
		int v = it->adjvex;
		if (!visited[v])
		{
			parent[v] = u;
			children++;
			articuPointUtil(v, visited, depth, low, parent, curDepth + 1, articuPoints);
			low[u] = min(low[u], low[v]);
			if (parent[u] == NIL && children > 1)//根节点
			{
				articuPoints[u] = true;
			}
			if (parent[u] != NIL && low[v] >= depth[u]) // 非根节点
			{
				articuPoints[u] = true;
			}
				
		}
		else if (v != parent[u])//v被访问过了，找到了回边且v不是u的双亲
		{
			low[u] = min(low[u], depth[v]);
		}
	}
	
}

//查找并输出关节点
void Graph::searchArticuPoint()
{
	bool* visited = new bool[numNodes];
	int* parent = new int[numNodes];
	int* low = new int[numNodes];
	int* depth = new int[numNodes];
	int artiPointnum = 0;
	for (int i = 0; i < numNodes; i++)
	{
		articuPoints[i] = false;
		parent[i] = NIL;
		visited[i] = false;
	}
	for (int i = 0; i < numNodes; i++)
	{
		if (!visited[i])
		{
			articuPointUtil(i, visited, depth, low, parent, 0, this->articuPoints);
		}
	}
	for (int i = 0; i < numNodes; i++)
	{
		if (articuPoints[i])
		{
			cout << i + 1;
		}
	}
}
//列出关节点
void Graph::displayArticuPoint()
{
	searchArticuPoint();
	int num = 0;
	for (int i = 0; i < numNodes; i++)
	{
		if (articuPoints[i])
		{
			cout << i+1 ;
			num++;
		}
	}
	if (num == 0)
	{
		cout << "该图中不含有关节点\n";
	}
	else
	{
		cout << "\n共有" << num << "个关节点\n";
	}
}
//此函数用于将关节点转换为非关节点
void Graph::articulareModify(int n)
{
	if (!articuPoints[n])
	{
		cout << "该结点不是关节点，请重新选择";
		return;
	}
	EdgeNode*u = vertexNodes[n].firstEdge;
	for (; u; u = u->next)
	{
		EdgeNode* v = u->next;
		while (v)
		{
			addEdge(v->adjvex, u->adjvex);
			v = v->next;
		}
	}
	articuPoints[n] = 0;
	cout << "更改成功";
	return;
}

//清空图
void Graph::clear()
{
	for (int i = 0; i < MAX_VEX; i++)
	{
		vertexNodes[i].val = 0;
		vertexNodes[i].firstEdge = NULL;
		articuPoints[i] = false;
	}
	numEdges = 0;
	numNodes = 0;
}






















