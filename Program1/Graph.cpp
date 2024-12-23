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
		cout << "��" << i + 1 << "�����" << "ֵΪ��" << vertexNodes[i].val << "�����ڵĽ���У�";
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
//��ӽڵ�
int Graph::addNode(int val) {
	if (numNodes < MAX_VEX) {
		vertexNodes[numNodes].val = val;
		vertexNodes[numNodes].firstEdge = NULL;
		numNodes++;
		return numNodes - 1;
	}
	else {
		cout << "�ڵ�������������" << endl;
	}
}

//��ӱ�
bool Graph::addEdge(int index1, int index2) {
	if (index1<0||index1>numNodes) 
	{
		cout <<" ���һ������\n";
		return false;
	}
	if (index2<0 || index2>numNodes)
	{
		cout << "����������\n";
		return false;
	}
	if (index1==index2) 
	{
		cout << "�����˽ڵ㲻����ͬ\n";
		return false;
	}
	EdgeNode* temp = vertexNodes[index1-1].firstEdge;
	while (temp)
	{
		if (temp->adjvex == index2)
		{
			cout << "�ñ��Ѵ���\n";
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
	cout << "�� (" << index1 << ", " << index2 << ") ��ӳɹ���\n";
	return true;
}
//ͨ��valֵ���ҽڵ�ĽǱ�
int Graph::searchPoint(int val)
{
	for (int i = 0; i < numNodes; i++) 
	{
		if (vertexNodes[i].val == val)return i;
	}
	return -1;
}
//�޸�valΪn�Ľڵ��valΪnewval
bool Graph::editNode(int n, int newval)
{
	if (n<=numNodes&&n>0) {
		vertexNodes[n].val = newval;
		cout << "�޸ĳɹ�\n";
		return true;
	}
	else
	{
		cout << "�ýڵ㲻��ͼ�У�����������\n";
		return false;
	}
}

//ɾ����
//bool Graph::deleteEdge(int val1, int val2) 
//{ 
//	bool flag = false;
//	int index1 = searchPoint(val1);
//	int index2 = searchPoint(val2);
//	if (index1 == -1)
//	{
//		cout << "ֵΪ " << val1 << " �Ľڵ㲻���ڣ�\n";
//		return false;
//	}
//	if (index2 == -1)
//	{
//		cout << "ֵΪ " << val2 << " �Ľڵ㲻���ڣ�\n";
//		return false;
//	}
//	//ɾ��val1�еı�
//	EdgeNode* temp = vertexNodes[index1].firstEdge;
//	EdgeNode* temp1 = temp;
//	if (temp == nullptr)
//	{
//		cout << "��Ҫɾ���ı߲�����\n";
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
//		cout << "��Ҫɾ���ı߲�����\n";
//		return false;
//	}
//	//ɾ��val2�еı�
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
//	cout << "ֵΪ" << val1 << "�Ľ�㵽ֵΪ" << val2 << "�Ľ��ı��ѱ�ɾ��\n";
//	return true;
//}
//
////ɾ���ڵ�
//bool Graph::deleteNode(int val)
//{
//	int index = searchPoint(val);
//	if (index == -1)
//	{
//		cout << "ֵΪ " << val << " �Ľڵ㲻���ڣ�\n";
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
//	cout << "ֵΪ" << val << "�Ľ���ѱ�ɾ��\n";
//	return true;
//}

//DFS_ȷ��ͼΪ��ͨͼ
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

//ȷ��ͼΪ��ͨͼ
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
	cout << "������Ĳ�����ͨͼ������\n";
	return false;
}

//DFS���ҹؽڵ�
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
			if (parent[u] == NIL && children > 1)//���ڵ�
			{
				articuPoints[u] = true;
			}
			if (parent[u] != NIL && low[v] >= depth[u]) // �Ǹ��ڵ�
			{
				articuPoints[u] = true;
			}
				
		}
		else if (v != parent[u])//v�����ʹ��ˣ��ҵ��˻ر���v����u��˫��
		{
			low[u] = min(low[u], depth[v]);
		}
	}
	
}

//���Ҳ�����ؽڵ�
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
//�г��ؽڵ�
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
		cout << "��ͼ�в����йؽڵ�\n";
	}
	else
	{
		cout << "\n����" << num << "���ؽڵ�\n";
	}
}
//�˺������ڽ��ؽڵ�ת��Ϊ�ǹؽڵ�
void Graph::articulareModify(int n)
{
	if (!articuPoints[n])
	{
		cout << "�ý�㲻�ǹؽڵ㣬������ѡ��";
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
	cout << "���ĳɹ�";
	return;
}

//���ͼ
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






















