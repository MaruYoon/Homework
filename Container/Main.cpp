#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>

using namespace std;


struct Info
{
	char* Name;
	int iKor;
	int iEng;
	int iMath;
	int Number;
};


vector<Info*> StudentList;
int Count = 0;

Info CreateInfo();
char* SetName();
void Initialize(Info* _tInfo);
void AddStudent();
void DeleteStudent();



int main(void)
{
	while (true)
	{
		system("cls");

		cout << "1. �л� ���� �߰�" << endl;
		cout << "2. �л� ���� ����" << endl;
		cout << "3. �л� ���� ����" << endl;
		cout << "4. �л� ���� ��ü ���" << endl;
		cout << "5. ����" << endl;


		int Choice = 0;

		cout << "�Է� : "; cin >> Choice;

		system("cls");

		switch (Choice)
		{
		case 1:
			AddStudent();
			break;

		case 2:
		{
			//** �л� ������ ã�� ��������� ��.
			Initialize(StudentList.front() );
		}
			break;

		case 3:
			DeleteStudent();
			break;

		case 4:
			for (vector<Info*>::iterator iter = StudentList.begin();
					iter != StudentList.end(); ++iter)
			{
				cout << (*iter)->Number << ". " << (*iter)->Name << endl;
				cout << "���� ���� : " << (*iter)->iKor << endl;
				cout << "���� ���� : " << (*iter)->iEng << endl;
				cout << "���� ���� : " << (*iter)->iMath << endl << endl;
			}
			
			break;

		case 5:
			exit(NULL);
			break;
		}

		system("pause");
	}

	return 0;
}

Info CreateInfo()
{
	Info tInfo;
	//struct Info�� tInfo��� �������� ����

	tInfo.Number = Count + 1;
	//tInfo(struct Info)���� Number�� +1�� Count�� �Ѱ��ش�.

	return tInfo;
	//struct Info�� ����
}

char* SetName()
{
	cout << "�л� �̸� �Է� : ";

	char buffer[128] = "";
	//128���� �迭�� ���� buffer��� char�� ���ڿ��̴�.

	cin >> buffer;
	//buffer�� �Է���

	char* pName = new char[strlen(buffer)];
	//���ڿ��� ũ�� ��ŭ ���� �Ҵ��� �� buffer�� pName�̶�� ������������ ����

	strcpy(pName, buffer);
	//�Է��� ũ�⸸ŭ�� ���۸� �����Ѵ�.


	return pName;
	//�ٽ� pName���� ����
}

void Initialize(Info* _tInfo)
{
	_tInfo->Name = SetName();

	cout << "���� ���� �Է� : ";
	cin >> _tInfo->iKor;

	cout << "���� ���� �Է� : ";
	cin >> _tInfo->iEng;

	cout << "���� ���� �Է� : ";
	cin >> _tInfo->iMath;
}


void AddStudent()
{
	cout << "** �л� ���� �߰� **" << endl << endl;

	Info tInfo = CreateInfo();
	Initialize(&tInfo);

	++Count;

	StudentList.push_back(&tInfo);
}


void DeleteStudent()
{
	cout << "** �л� ���� ���� **" << endl << endl;

	if (Count == 1)
	{
		StudentList.clear();
		Count = 0;
	}
	else
	{
		int n = 0;
		cout << "�л� ��ȣ �Է� : ";
		cin >> n;

		for (vector<Info*>::iterator iter = StudentList.begin();
			iter != StudentList.end(); )
		{
			if ((*iter)->Number == n)
				iter = StudentList.erase(iter);
			else
				++iter;
		}
	}
}
