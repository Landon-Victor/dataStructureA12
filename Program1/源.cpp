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
			cout << "��ѡ���ȡ��ʽ��";
			cin >> cmd;
			if (cmd == 0)
				break;
			switch (cmd)
			{
			case 1:
			{
				Add add(g);
				// ����������뺯�������ýڵ�������ΧΪ5��20������������Ϊ50���ɰ����������
				std::cout << "���Խ������ͼ����..." << std::endl;
				if (add.randomInput(5, 20, 50)) {
					inputFlag = true;
					std::cout << "��������ͼ���룬�ɽ��к���������" << std::endl;
				}
				else {
					// ����������ʧ�ܣ����������������Ӧ����ʾ�����߼���������ʾ�û�����ѡ���
					system("cls");
					printf("���ͼ����ʧ�ܣ�������ѡ�������ʽ��\n");
					Sleep(1000);
					system("cls");
				}
				break;
			}
			case 2:
			{
				/*���ļ�����*/
				string filename;
				cout << "�������ļ���:";
				cin >> filename;
				filename += ".txt";
				inputFlag = add.loadFromFile(filename);
				break;
			}
			case 3:
			{
				/*�˹�����*/
				add.inputGraph();
				string filename;
				cout << "����������Ҫ������ļ���";
				cin >> filename;
				filename += ".txt";
				add.saveToFile(filename);
				inputFlag = true;
				break;
			}
			default:
				system("cls");
				printf("��ѡ����ȷ����ţ�\n");
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
				printf(" ******************��   ��****************\n");
				printf("                 0.�˳�\n");
				printf("                 1.������һ��\n");
				printf("                 2.���ͼ\n");
				printf("                 3.���Ľ���ֵ\n");
				printf("                 4.��ѯͳ�ƹؽڵ�\n");
				printf("                 5.���ؽڵ�ת��Ϊ�ǹؽڵ�\n");
				printf(" ******************************************\n");
				printf("\n");
			}
			cout << "��ѡ���ܣ�";
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
					cout << "������Ҫ�޸ĵĽ����";
					int n;
					cin >> n;
					cout << "�ýڵ����ڵ�ֵΪ��" << add.g.valRetrun(n) << "\n";
					cout << "Ҫ��ֵ��Ϊ��";
					int newval;
					cin >> newval;
					if (newval == add.g.valRetrun(n))
					{
						cout << "��ֵΪ�ý�����ڵ�ֵ�������²���\n";
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
				cout << "������ؽڵ�����:";
				cin >> n;
				add.g.articulareModify(n);
				control = false;
				break;
			}
			default:
				system("cls");
				printf("��ѡ����ȷ����ţ�\n");
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
