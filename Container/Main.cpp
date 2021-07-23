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

		cout << "1. 학생 정보 추가" << endl;
		cout << "2. 학생 정보 변경" << endl;
		cout << "3. 학생 정보 삭제" << endl;
		cout << "4. 학생 정보 전체 출력" << endl;
		cout << "5. 종료" << endl;


		int Choice = 0;

		cout << "입력 : "; cin >> Choice;

		system("cls");

		switch (Choice)
		{
		case 1:
			AddStudent();
			break;

		case 2:
		{
			//** 학생 정보를 찾아 전달해줘야 함.
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
				cout << "국어 점수 : " << (*iter)->iKor << endl;
				cout << "영어 점수 : " << (*iter)->iEng << endl;
				cout << "수학 점수 : " << (*iter)->iMath << endl << endl;
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
	//struct Info는 tInfo라고 지역변수 선언

	tInfo.Number = Count + 1;
	//tInfo(struct Info)안의 Number에 +1한 Count를 넘겨준다.

	return tInfo;
	//struct Info로 리턴
}

char* SetName()
{
	cout << "학생 이름 입력 : ";

	char buffer[128] = "";
	//128개의 배열을 가진 buffer라는 char는 문자열이다.

	cin >> buffer;
	//buffer를 입력해

	char* pName = new char[strlen(buffer)];
	//문자열의 크기 만큼 동적 할당을 한 buffer를 pName이라는 지역변수에게 전달

	strcpy(pName, buffer);
	//입력한 크기만큼의 버퍼를 저장한다.


	return pName;
	//다시 pName으로 리턴
}

void Initialize(Info* _tInfo)
{
	_tInfo->Name = SetName();

	cout << "국어 점수 입력 : ";
	cin >> _tInfo->iKor;

	cout << "영어 점수 입력 : ";
	cin >> _tInfo->iEng;

	cout << "수학 점수 입력 : ";
	cin >> _tInfo->iMath;
}


void AddStudent()
{
	cout << "** 학생 정보 추가 **" << endl << endl;

	Info tInfo = CreateInfo();
	Initialize(&tInfo);

	++Count;

	StudentList.push_back(&tInfo);
}


void DeleteStudent()
{
	cout << "** 학생 정보 삭제 **" << endl << endl;

	if (Count == 1)
	{
		StudentList.clear();
		Count = 0;
	}
	else
	{
		int n = 0;
		cout << "학생 번호 입력 : ";
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
