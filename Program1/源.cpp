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
		while (!inputFlag)
		{
			add.display();
			int cmd;
			cout << "请选择读取方式：";
			cin >> cmd;
			if (cmd == 0)
				break;
			switch (cmd)
			{
			case 1:
			{
				/*随机读入*/
				cout << "正在随机读入。。。" << endl;
				break;
			}
			case 2:
			{
				/*从文件读入*/
				string filename;
				cout << "请输入文件名:";
				cin >> filename;
				filename += ".txt";
				inputFlag = add.loadFromFile(filename);
				break;
			}
			case 3:
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
			default:
				system("cls");
				printf("请选择正确的序号！\n");
				Sleep(1000);
				system("cls");
				getchar();
				break;
			}
		}

		Sleep(1000);
		system("cls");
		inputFlag = false;
		bool control = false;
		while (!operFlag)
		{
			int cmd = -1;
			if (!control)
			{
				Sleep(1000);
				system("cls");
				getchar();
				printf(" ******************操   作****************\n");
				printf("                 0.退出\n");
				printf("                 1.返回上一级\n");
				printf("                 2.输出图\n");
				printf("                 3.更改结点的值\n");
				printf("                 4.查询统计关节点\n");
				printf("                 5.将关节点转化为非关节点\n");
				printf(" ******************************************\n");
				printf("\n");
			}
			cout << "请选择功能：";
			cin >> cmd;
			if (cmd == 0)
				return 0;
			else if (cmd == 1)
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
						jus=add.g.editNode(n, newval);
					}
				}
				control = false;
				break;
			}
			case 4:
			{
				add.g.displayArticuPoint();
				control = true;
				break;
			}
			case 5:
			{
				int n;
				cout << "请输入关节点的序号:";
				cin >> n;
				add.g.articulareModify(n);
				control = false;
				break;
			}
			default:
				system("cls");
				printf("请选择正确的序号！\n");
				Sleep(1000);
				system("cls");
				getchar();
				break;
			}

		}
		operFlag = false;
	}
	


	return 0;
}
