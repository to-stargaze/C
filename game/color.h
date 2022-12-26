#include <stdio.h>
#include <Windows.h>

void setColor(unsigned short text,unsigned short back){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),text|(back << 4));
}


void green(){
  // 밝은 녹색
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void red(){
  // 밝은 적색
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void white(){
  // 밝은 백색
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void gray(){
  // 원래의 회색 글자로
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void backwhite(){
	setColor(15,15);
}//배경색을 흰색으로 
void backblack(){
	setColor(15,0);
}//배경색을 검정으로 
void backgray7(){
	setColor(7,7);
}//배경색을 밝은 회색이였나? 
void backgray8(){
	setColor(8,8);
}//어두운회색? 
