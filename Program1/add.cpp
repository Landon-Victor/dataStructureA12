#include <iostream>
#include <cstdlib> // 用于生成随机数相关函数
#include <ctime>   // 用于设置随机数种子
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

//显示文件添加菜单
void Add::display()
{
	printf(" ******************操   作****************\n");
	printf("                 -1.退出\n");
	printf("                 1.随机读入\n");
	printf("                 2.文件读入\n");
	printf("                 3.人工输入\n");
	printf(" ******************************************\n");
	printf("\n");
}

// 从文件加载图
bool Add::loadFromFile(const string& filename) 
{
    ifstream curFile(filename);
    if (!curFile)
    {
        cerr << "无法打开文件: " << filename << endl;
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
        // 获取节点值并添加
        int nodeValue = stoi(line.substr(0, pos));
        g.addNode(nodeValue);
    }
    curFile.close();
    ifstream curFile1(filename);
    if (!curFile1)
    {
        cerr << "无法打开文件: " << filename << endl;
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

// 保存图到文件
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
    cout << "当前图的数据已成功保存至文件" << filename << endl;
}

//人工读入数据
void Add::inputGraph() 
{
    g.clear();

    cout << "请输入节点数量: ";
    while (true)
    {
        if (cin >> g.numNodes)
        {
            if (g.numNodes > MAX_VEX)
            {
                cerr << "节点数量超过最大限制: " << MAX_VEX << endl;
                cout << "请重新输入:";
            }
            else break;
        }
        else 
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            printf("！！！非法输入！！！\n请重新输入！\n");
        }
        
    }
    // 输入每个节点的值
    for (int i = 0; i < g.numNodes; ++i) 
    {
        cout << "请输入编号为 " << i + 1 << "号结点的值: ";
        if (cin >> g.vertexNodes[i].val) {}
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            printf("！！！非法输入！！！\n将重新输入！\n");
            --i;
        }
    }
    cout << "请输入边的数量: "; 
    int num=0;
    while (1)
    {
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            printf("！！！非法输入！！！\n请重新输入！\n");
        }
        else if (num > g.numNodes * (g.numNodes - 1) / 2)
            cout << "边的值不合法,请重新输入\n";
        else
            //唯一出口
            break;
    }
    // 输入每条边
    for (int i = 0; i < num; ++i) 
    {
        int u=0, v=0;
        cout << "请输入边 " << i + 1 << " 的两个端点的编号 (格式: u v): ";
        while (!(cin >> u >> v))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            printf("！！！非法输入！！！\n请重新输入！\n");
        }
        if (!g.addEdge(u - 1, v - 1)) 
        {
            cout << "该边输入失败，将重新输入\n";
            --i;
        }
    }
    cout << "图输入完成!!!" << endl;
}

bool Add::randomInput(int minNodes, int maxNodes, int maxEdges) {
    // 设置随机数种子，保证每次运行生成的随机序列不同（基于当前时间
    srand(static_cast<unsigned int>(time(nullptr)));

    // 随机生成节点数量，范围在minNodes到maxNodes之间
    int numNodes = rand() % (maxNodes - minNodes + 1) + minNodes;
    g.clear();

    // 随机生成每个节点的值，并添加节点
    for (int i = 0; i < numNodes; ++i) {
        int nodeValue = i; 
        g.addNode(nodeValue);
    }

    // 先构建一个连通的初始图结构（例如生成一个树状结构保证连通）
    for (int i = 1; i < numNodes; ++i) {
        g.addEdge(g.vertexNodes[0].val, g.vertexNodes[i].val);
    }
    int currentEdges = numNodes - 1; // 已有的边数量（初始连通结构的边数）

    // 随机生成剩余边的数量，范围在0到（maxEdges - currentEdges）之间，确保总边数不超过maxEdges且能保证连通性
    int remainingEdges = rand() % (maxEdges - currentEdges + 1);
    int numEdges = currentEdges + remainingEdges;

    // 随机添加剩余的边，要确保边连接的节点是已存在的节点，且添加后图依然保持连通
    for (int i = currentEdges; i < numEdges; ++i) {
        int u, v;
        u = rand() % numNodes;
        v = rand() % numNodes;
        while (u == v||u==0||v==0) { // 避免自环边，重新选择节点
           v = rand() % numNodes;
           u = rand() % numNodes;
        }
        g.vertexNodes[u].val = u;
        g.vertexNodes[v].val = v;
        g.addEdge(g.vertexNodes[u].val, g.vertexNodes[v].val);
    }
    return true;
}

// 使用BFS判断图是否连通的辅助函数
bool Add::isConnected() {
    vector<bool> visited(g.numNodes, false);
    queue<int> q;
    // 从第一个节点开始进行BFS遍历
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

    // 检查是否所有节点都被访问到，若都访问到了则图是连通的
    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}