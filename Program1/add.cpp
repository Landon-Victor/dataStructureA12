#include"Add.h"
#include <fstream>
#include <sstream>
#include<string>

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
	printf("                 0.退出\n");
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
    while (getline(curFile, line))
    {
        size_t pos = line.find(':');
        if (pos == string::npos)
        {
            continue;
        }

        // 获取节点值并添加
        int nodeValue = stoi(line.substr(0, pos));
        g.addNode(nodeValue);
        
        string edges = line.substr(pos + 1);
        istringstream edgeStream(edges);
        string adjValue;
        while (edgeStream >> adjValue) 
        {
            g.addNode(stoi(adjValue)); 
            g.addEdge(nodeValue, stoi(adjValue));
        }
    }

    curFile.close();
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
            printf("%d\n", temp->adjvex);
            if (temp->adjvex >= 0 && temp->adjvex < g.numNodes)
            {
                curFile << " " << g.vertexNodes[temp->adjvex].val;
            }
            else
            {
                // 如果 adjvex 不合法，处理错误  
                std::cerr << "Error: Invalid adjacent vertex index: " << temp->adjvex << std::endl;
            }
            temp = temp->next;
        }
        curFile << endl;
    }
    curFile.close();
}

//人工读入数据
void Add::inputGraph() 
{
    cout << "请输入节点数量: ";
    while (true)
    {
        cin >> g.numNodes;
        if (g.numNodes > MAX_VEX)
        {
            cerr << "节点数量超过最大限制: " << MAX_VEX << endl;
            cout << "请重新输入:";
        }
        else break;
    }
    // 输入每个节点的值
    for (int i = 0; i < g.numNodes; ++i) 
    {
        cout << "请输入节点 " << i + 1 << " 的值: ";
        cin >> g.vertexNodes[i].val;
    }
    cout << "请输入边的数量: "; 
    int num=0;
    cin >>num;
    // 输入每条边
    for (int i = 0; i < num; ++i) 
    {
        int u, v;
        cout << "请输入边 " << i + 1 << " 的两个端点 (格式: u v): ";
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << "图输入完成!!!" << endl;
}