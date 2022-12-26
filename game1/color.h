#include <stdio.h>
#include <Windows.h>

void setColor(unsigned short text,unsigned short back){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),text|(back << 4));
}


void green(){
  // ���� ���
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void red(){
  // ���� ����
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void white(){
  // ���� ���
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void gray(){
  // ������ ȸ�� ���ڷ�
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void backwhite(){
	setColor(15,15);
}//������ ������� 
void backblack(){
	setColor(15,0);
}//������ �������� 
void backgray7(){
	setColor(7,7);
}//������ ���� ȸ���̿���? 
void backgray8(){
	setColor(8,8);
}//��ο�ȸ��? 
