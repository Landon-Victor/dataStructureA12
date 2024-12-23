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

//��ʾ�ļ���Ӳ˵�
void Add::display()
{
	printf(" ******************��   ��****************\n");
	printf("                 0.�˳�\n");
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
    while (getline(curFile, line))
    {
        size_t pos = line.find(':');
        if (pos == string::npos)
        {
            continue;
        }

        // ��ȡ�ڵ�ֵ�����
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
            printf("%d\n", temp->adjvex);
            if (temp->adjvex >= 0 && temp->adjvex < g.numNodes)
            {
                curFile << " " << g.vertexNodes[temp->adjvex].val;
            }
            else
            {
                // ��� adjvex ���Ϸ����������  
                std::cerr << "Error: Invalid adjacent vertex index: " << temp->adjvex << std::endl;
            }
            temp = temp->next;
        }
        curFile << endl;
    }
    curFile.close();
}

//�˹���������
void Add::inputGraph() 
{
    cout << "������ڵ�����: ";
    while (true)
    {
        cin >> g.numNodes;
        if (g.numNodes > MAX_VEX)
        {
            cerr << "�ڵ����������������: " << MAX_VEX << endl;
            cout << "����������:";
        }
        else break;
    }
    // ����ÿ���ڵ��ֵ
    for (int i = 0; i < g.numNodes; ++i) 
    {
        cout << "������ڵ� " << i + 1 << " ��ֵ: ";
        cin >> g.vertexNodes[i].val;
    }
    cout << "������ߵ�����: "; 
    int num=0;
    cin >>num;
    // ����ÿ����
    for (int i = 0; i < num; ++i) 
    {
        int u, v;
        cout << "������� " << i + 1 << " �������˵� (��ʽ: u v): ";
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << "ͼ�������!!!" << endl;
}