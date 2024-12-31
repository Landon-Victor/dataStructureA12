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
			cout << "��ѡ���ȡ��ʽ��";
			cin >> cmd;
			if (cmd == -1)
				return 0;
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
				cin.clear();
				while (cin.get() != '\n')
					continue;
				printf("�������Ƿ����룡����\n��ѡ����ȷ����ţ�\n");
				Sleep(2000);
				system("cls");
				break;
			}
		}



		Sleep(2000);
		system("cls");
		cout << "���ݼ��سɹ�";
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
				printf(" ******************��   ��****************\n");
				printf("                 -1.�˳�\n");
				printf("                 1.������һ�����¶���ͼ\n");
				printf("                 2.���ͼ\n");
				printf("                 3.���Ľ�����Ϣ\n");
				printf("                 4.����½��\n");
				printf("                 5.����±�\n");
				printf("                 6.ɾ��ĳ���\n");
				printf("                 7.ɾ��ĳ��\n");
				printf("                 8.��ѯĳ�����Ϣ\n");
				printf("                 9.��ѯͳ�ƹؽڵ�\n");
				printf("                 10.���ؽڵ�ת��Ϊ�ǹؽڵ�\n");
				printf(" ******************************************\n");
				printf("\n");
			}
			cout << "��ѡ���ܣ�";
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
						jus = add.g.editNode(n, newval);
						cout << "�޸ĳɹ�\n";
					}
				}
				control = false;
				break;
			}
			case 4:
			{
				cout << "�������½ڵ��ֵ\n";
				int val = 0;
				while (!(cin >> val))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("�������Ƿ����룡����\n���������룡\n");
				}
				if (!add.g.addNode(val))
					cout << "����½ڵ�ʧ��";
				else
					cout << "����½ڵ�ɹ�\n";
				break;
			}
			case 5:
			{
				cout << "�������±ߵ����˵��ţ��ո�ֿ���\n";
				int u = 0, v = 0;
				while (!(cin >> u >> v))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("�������Ƿ����룡����\n���������룡\n");
				}
	
				if (!add.g.addEdge(u - 1, v - 1))
					cout << "����±�ʧ��";
				else
					cout << "��ӱ߳ɹ�\n";
				break;
			}
			case 6:
			{
				cout << "������Ҫɾ�����ı��\n";
				int n=0;
				while (!(cin >> n))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("�������Ƿ����룡����\n���������룡\n");
				}
				if (!(add.g.deleteNode(n - 1)))
					cout << "ɾ�����ʧ��";
				break;
			}
			case 7:
			{
				cout << "������Ҫɾ���ߵ����˵��ţ��ո������\n";
				int u = 0, v = 0;
				while (!(cin >> u >> v))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("�������Ƿ����룡����\n���������룡\n");
				}
				if (add.g.deleteEdge(u - 1, v - 1))
				{
					cout << "���Ϊ" << u << "�Ľ������Ϊ" << v << "�Ľ��ı��ѱ�ɾ��\n";
				}
				else
					cout << "ɾ����ʧ��";
				control = false;
				break;
			}
			case 8:
			{
				cout << "������Ҫ��ѯ���ı��\n";
				int n = 0;
				while (!(cin >> n))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					printf("�������Ƿ����룡����\n���������룡\n");
				}
				if (n >add.g.numnodeReturn()||n<=0)
				{
					cout << "����Υ����" << "������1~" << add.g.numnodeReturn() << "֮�������\n";
				}
				else cout <<"��"<<n<<"���ڵ��ֵΪ"<< add.g.valRetrun(n) << endl;
				control = false;
				break;
			}
			case 9:
			{
				if (!add.g.isConnected())
				{
					cout << "��ǰͼ�Բ���ͨ���������ӱߵȲ�������ͼ\n";
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
					cout << "��ǰͼ�Բ���ͨ���������ӱߵȲ�������ͼ\n";
					break;
				}
				int n;
				cout << "������ؽڵ�����:";
				cin >> n;
				add.g.articulareModify(n);
			    control = false;;
				break;
			}
			default:
				cout << "default";
				cin.clear();
				while (cin.get() != '\n')
					continue;
				printf("�������Ƿ����룡����\n��ѡ����ȷ����ţ�\n");
				Sleep(2000);
				system("cls");
				break;
			}
		}
		operFlag = false;
	}
	return 0;
}
