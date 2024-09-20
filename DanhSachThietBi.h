#ifndef DanhSachThietBi_h_
#define DanhSachThietBi_h_

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 255

struct Date{
	int day;
	int month;
	int year;
};
typedef Date date;

struct Item{
	int code;
	char name_item[MAX_SIZE];
	float price;
	int amount;
	int amount_inventory;
	char goods_condition[MAX_SIZE];
	date input_date;	
};
typedef Item ITEM;

struct Node{
	ITEM data;
	Node *pNext;	
};
typedef Node NODE;

struct List{
	NODE *pHead;
	NODE *pTail;
};
typedef List LIST;
/*
	khoi tao danh sach rong
*/
void init(LIST &l);
/*
	tao node
*/
NODE* getNode(ITEM newitem);
/*
	them node vao dau danh sach
*/
void addHead(LIST &l, ITEM item);
/*
	them node vao cuoi danh sach
*/
void addTail(LIST &l, ITEM item);
/*
	kiem tra da EOF hay co ky tu '\n'
*/
int eof_or_line_break(char c);
/*
	doc tung dong du lieu trong file duoi dang chuoi
*/
void readline(char * line, int max_lengh, FILE *file);
/*
	doc file
*/
void read_file_data(FILE *file, ITEM &item , LIST &l, int count);
/*
	dem so luong cac mat hang trong file
*/
void count_file(int &count);

#endif