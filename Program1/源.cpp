#include <iostream>
#include<Windows.h>
#include"Graph.h"
#include"Add.h"


using namespace std;

int main()
{
	while (true)
	{
		bool inputFlag = false;
		bool operFlag = false;
		Graph g;
		Add add(g);
		int cmd = 0;
		while (!inputFlag)
		{
			system("cls");
			add.display();
			cout << "请选择读取方式：";
			cin >> cmd;
			if (cmd == -1)
				return 0;
			switch (cmd)
			{
			case 1:
			{
				/*从文件读入*/
				string filename;
				cout << "请输入文件名:";
				cin >> filename;
				filename += ".txt";
				inputFlag = add.loadFromFile(filename);
				break;
			}
			case 2:
			{
				/*人工输入*/
				add.inputGraph();
				string filename;
				cout << "请输入你需要保存的文件名";
				cin >> filename;
				filename += ".txt";
				add.saveToFile(filename);
				inputFlag = true;
				break;
			}
			case 3:
			{
				cout << "请输入最小节点数 (minNodes): ";
				int minNodes, maxNodes, maxEdges;
				while (!(cin >> minNodes))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("！！！非法输入！！！\n请重新输入！\n");
					cout << "请输入最小节点数 (minNodes): ";
				}
				/*if (minNodes <= 0)
				{
					printf("!!!请输入合规的数字");
					Sleep(2000);
					break;
				}*/
				/*cin >> minNodes;*/
				cout << "请输入最大节点数 (maxNodes): ";
				while (!(cin >> maxNodes))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("！！！非法输入！！！\n请重新输入！\n");
					cout << "请输入最大节点数 (minNodes): ";
				}
				/*if (maxNodes <= 0||maxNodes<minNodes)
				{
					printf("!!!请输入合规的数字");
					Sleep(2000);
					break;
				}*/
				cout << "请输入最大边数 (maxEdges): ";
				while (!(cin >> maxEdges))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("！！！非法输入！！！\n请重新输入！\n");
					cout << "请输入最dabian数 (maxEdges): ";
				}
				/*if (maxEdges <= 0)
				{
					printf("!!!请输入合规的数字");
					break;
				}*/
				if (minNodes > 0 && maxNodes >= minNodes && maxEdges > 0) {
					std::cout << "尝试进行随机图输入..." << std::endl;
					if (add.randomInput(minNodes, maxNodes, maxEdges)) {
						std::cout << "已完成随机图输入，可进行后续操作。" << std::endl;
						inputFlag = true;
					}
					else {
						std::cout << "随机图输入失败，请重新选择操作方式！" << std::endl;
					}
				}
				else {
					cout << "输入不合法，请确保 0 <= minNodes <= maxNodes 且 maxEdges >= 0。" << endl;
					Sleep(2000);
				}

				break;
			}
			default:
				cin.clear();
				while (cin.get() != '\n')
					continue;
				printf("！！！非法输入！！！\n请选择正确的序号！\n");
				Sleep(2000);
				system("cls");
				break;
			}
		}



		Sleep(2000);
		system("cls");
		cout << "数据加载成功";
		Sleep(2000);
		system("cls");
		inputFlag = false;
		bool control = false;



		while (!operFlag)
		{
			int cmd = -1;
			if (!control)
			{
				Sleep(2000);
				system("cls");
				printf(" ******************操   作****************\n");
				printf("                 -1.退出\n");
				printf("                 1.返回上一级重新读入图\n");
				printf("                 2.输出图\n");
				printf("                 3.更改结点的信息\n");
				printf("                 4.添加新结点\n");
				printf("                 5.添加新边\n");
				printf("                 6.删除某结点\n");
				printf("                 7.删除某边\n");
				printf("                 8.查询某结点信息\n");
				printf("                 9.查询统计关节点\n");
				printf("                 10.将关节点转化为非关节点\n");
				printf("                 11.无向图可视化\n");
				printf(" ******************************************\n");
				printf("\n");
			}
			cout << "请选择功能：";
			cin >> cmd;
			if (cmd == -1)
				return 0;
			if (cmd == 1)
				break;
			switch (cmd)
			{
			case 2:
			{
				add.g.printGrgph();
				control = true;
				break;
			}
			case 3:
			{
				int jus = false;
				while (!jus)
				{
					cout << "请输入要修改的结点编号";
					int n;
					cin >> n;
					cout << "该节点现在的值为：" << add.g.valRetrun(n) << "\n";
					cout << "要将值改为：";
					int newval;
					cin >> newval;
					if (newval == add.g.valRetrun(n))
					{
						cout << "该值为该结点现在的值，请重新操作\n";
						break;
					}
					else
					{
						jus = add.g.editNode(n, newval);
					}
				}
				control = false;
				break;
			}
			case 4:
			{
				cout << "请输入新节点的值\n";
				int val = 0;
				while (!(cin >> val))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("！！！非法输入！！！\n请重新输入！\n");
				}
				if (!add.g.addNode(val))
					cout << "添加新节点失败";
				else
					cout << "添加新节点成功\n";
				control = false;
				break;
			}
			case 5:
			{
				cout << "请输入新边的两端点编号（空格分开）\n";
				int u = 0, v = 0;
				while (!(cin >> u >> v))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("！！！非法输入！！！\n请重新输入！\n");
				}
	
				if (!add.g.addEdge(u - 1, v - 1))
					cout << "添加新边失败";
				else
					cout << "添加边成功\n";
				control = false;
				break;
			}
			case 6:
			{
				cout << "请输入要删除结点的编号\n";
				int n=0;
				while (!(cin >> n))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("！！！非法输入！！！\n请重新输入！\n");
				}
				if (!(add.g.deleteNode(n - 1)))
					cout << "删除结点失败";
				control = false;
				break;
			}
			case 7:
			{
				cout << "请输入要删除边的两端点编号（空格隔开）\n";
				int u = 0, v = 0;
				while (!(cin >> u >> v))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("！！！非法输入！！！\n请重新输入！\n");
				}
				if (add.g.deleteEdge(u - 1, v - 1))
				{
					cout << "编号为" << u << "的结点与编号为" << v << "的结点的边已被删除\n";
				}
				else
					cout << "删除边失败";
				control = false;
				break;
			}
			case 8:
			{
				cout << "请输入要查询结点的编号\n";
				int n = 0;
				while (!(cin >> n))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("！！！非法输入！！！\n请重新输入！\n");
				}
				if (n >add.g.numnodeReturn()||n<=0)
				{
					cout << "输入违法，" << "请输入1~" << add.g.numnodeReturn() << "之间的数字\n";
				}
				else cout <<"第"<<n<<"个节点的值为"<< add.g.valRetrun(n) << endl;
				control = false;
				break;
			}
			case 9:
			{
				if (!add.g.isConnected())
				{
					cout << "当前图仍不连通，请进行添加边等操作更改图\n";
					control = false;
					break;
				}
				add.g.displayArticuPoint();
				control = true;
				break;
			}
			case 10:
			{
				if (!add.g.isConnected())
				{
					cout << "当前图仍不连通，请进行添加边等操作更改图\n";
					break;
				}
				int n;
				cout << "请输入关节点的序号:";
				cin >> n;
				add.g.articulareModify(n);
			    control = false;
				break;
			}
			/*case 11:
			{
				cout << "请输入无向图存储文件名称\n";
				string filename1;
				cin >> filename1;
				if (!(add.g.plot(filename1)))
				{
					cerr<<"生成图失败\n";
				}
				control = false;
				break;
			}*/
			default:
				cout << "default";
				cin.clear();
				while (cin.get() != '\n')
					continue;
				printf("！！！非法输入！！！\n请选择正确的序号！\n");
				Sleep(2000);
				system("cls");
				break;
			}
		}
		operFlag = false;
	}
	return 0;
}
