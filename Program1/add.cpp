#include <iostream>
#include <cstdlib> // ���������������غ���
#include <ctime>   // �����������������
#include <fstream>
#include <sstream>
#include <queue>
#include <string>
#include "Graph.h"
#include "Add.h"
using namespace std; 

Add::Add(const Graph&g):g(g)
{

}

Add::~Add()
{

}

//��ʾ�ļ���Ӳ˵�
void Add::display()
{
	printf(" ******************��   ��****************\n");
	printf("                 -1.�˳�\n");
	printf("                 1.�������\n");
	printf("                 2.�ļ�����\n");
	printf("                 3.�˹�����\n");
	printf(" ******************************************\n");
	printf("\n");
}

// ���ļ�����ͼ
bool Add::loadFromFile(const string& filename) 
{
    ifstream curFile(filename);
    if (!curFile)
    {
        cerr << "�޷����ļ�: " << filename << endl;
        return false;
    }
    g.clear();
    string line;
    size_t pos;
    while (getline(curFile, line))
    {
        pos = line.find(':');
        if (pos == string::npos)
        {
            continue;
        }
        // ��ȡ�ڵ�ֵ�����
        int nodeValue = stoi(line.substr(0, pos));
        g.addNode(nodeValue);
    }
    curFile.close();
    ifstream curFile1(filename);
    if (!curFile1)
    {
        cerr << "�޷����ļ�: " << filename << endl;
        return false;
    }
    while (getline(curFile1, line))
    {
        pos = line.find(':');
        if (pos == string::npos)
        {
            continue;
        }
        int nodeValue = stoi(line.substr(0, pos));
        string edges = line.substr(pos + 1);
        istringstream edgeStream(edges);
        string adjValue;
        while (edgeStream >> adjValue)
        {
            g.addEdge(nodeValue-1, stoi(adjValue)-1);
        }
    }
    curFile1.close();
}

// ����ͼ���ļ�
void Add::saveToFile(const string& filename) const
{
    ofstream curFile(filename);
    for (int i = 0; i < g.numNodes; ++i)
    {
        curFile << g.vertexNodes[i].val << ":";
        EdgeNode* temp = g.vertexNodes[i].firstEdge;
        while (temp != NULL)
        {
            curFile << " " << (temp->adjvex) + 1;
            temp = temp->next;
        }
        curFile << endl;
    }
    curFile.close();
    cout << "��ǰͼ�������ѳɹ��������ļ�" << filename << endl;
}

//�˹���������
void Add::inputGraph() 
{
    g.clear();

    cout << "������ڵ�����: ";
    while (true)
    {
        if (cin >> g.numNodes)
        {
            if (g.numNodes > MAX_VEX)
            {
                cerr << "�ڵ����������������: " << MAX_VEX << endl;
                cout << "����������:";
            }
            else break;
        }
        else 
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            printf("�������Ƿ����룡����\n���������룡\n");
        }
        
    }
    // ����ÿ���ڵ��ֵ
    for (int i = 0; i < g.numNodes; ++i) 
    {
        cout << "��������Ϊ " << i + 1 << "�Ž���ֵ: ";
        if (cin >> g.vertexNodes[i].val) {}
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            printf("�������Ƿ����룡����\n���������룡\n");
            --i;
        }
    }
    cout << "������ߵ�����: "; 
    int num=0;
    while (1)
    {
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            printf("�������Ƿ����룡����\n���������룡\n");
        }
        else if (num > g.numNodes * (g.numNodes - 1) / 2)
            cout << "�ߵ�ֵ���Ϸ�,����������\n";
        else
            //Ψһ����
            break;
    }
    // ����ÿ����
    for (int i = 0; i < num; ++i) 
    {
        int u=0, v=0;
        cout << "������� " << i + 1 << " �������˵�ı�� (��ʽ: u v): ";
        while (!(cin >> u >> v))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            printf("�������Ƿ����룡����\n���������룡\n");
        }
        if (!g.addEdge(u - 1, v - 1)) 
        {
            cout << "�ñ�����ʧ�ܣ�����������\n";
            --i;
        }
    }
    cout << "ͼ�������!!!" << endl;
}

bool Add::randomInput(int minNodes, int maxNodes, int maxEdges) {
    // ������������ӣ���֤ÿ���������ɵ�������в�ͬ�����ڵ�ǰʱ��
    srand(static_cast<unsigned int>(time(nullptr)));

    // ������ɽڵ���������Χ��minNodes��maxNodes֮��
    int numNodes = rand() % (maxNodes - minNodes + 1) + minNodes;
    g.clear();

    // �������ÿ���ڵ��ֵ������ӽڵ�
    for (int i = 0; i < numNodes; ++i) {
        int nodeValue = i; 
        g.addNode(nodeValue);
    }

    // �ȹ���һ����ͨ�ĳ�ʼͼ�ṹ����������һ����״�ṹ��֤��ͨ��
    for (int i = 1; i < numNodes; ++i) {
        g.addEdge(g.vertexNodes[0].val, g.vertexNodes[i].val);
    }
    int currentEdges = numNodes - 1; // ���еı���������ʼ��ͨ�ṹ�ı�����

    // �������ʣ��ߵ���������Χ��0����maxEdges - currentEdges��֮�䣬ȷ���ܱ���������maxEdges���ܱ�֤��ͨ��
    int remainingEdges = rand() % (maxEdges - currentEdges + 1);
    int numEdges = currentEdges + remainingEdges;

    // ������ʣ��ıߣ�Ҫȷ�������ӵĽڵ����Ѵ��ڵĽڵ㣬����Ӻ�ͼ��Ȼ������ͨ
    for (int i = currentEdges; i < numEdges; ++i) {
        int u, v;
        u = rand() % numNodes;
        v = rand() % numNodes;
        while (u == v||u==0||v==0) { // �����Ի��ߣ�����ѡ��ڵ�
           v = rand() % numNodes;
           u = rand() % numNodes;
        }
        g.vertexNodes[u].val = u;
        g.vertexNodes[v].val = v;
        g.addEdge(g.vertexNodes[u].val, g.vertexNodes[v].val);
    }
    return true;
}

// ʹ��BFS�ж�ͼ�Ƿ���ͨ�ĸ�������
bool Add::isConnected() {
    vector<bool> visited(g.numNodes, false);
    queue<int> q;
    // �ӵ�һ���ڵ㿪ʼ����BFS����
    q.push(g.vertexNodes[0].val);
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        int m = g.searchPoint(current);
        EdgeNode* temp = g.vertexNodes[m].firstEdge;
        while (temp != NULL) {
            int adjNode = g.vertexNodes[temp->adjvex].val;
            int adjIndex = g.searchPoint(adjNode);
            if (!visited[adjIndex]) {
                visited[adjIndex] = true;
                q.push(adjNode);
            }
            temp = temp->next;
        }
    }

    // ����Ƿ����нڵ㶼�����ʵ����������ʵ�����ͼ����ͨ��
    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}