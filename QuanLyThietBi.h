#include "DanhSachThietBi.h"
#ifndef QuanLiThietBi_h_
#define QuanLiThietBi_h_

/*
	tieu de 
*/
void Heading();
/*
	in mot mat hang
*/
void print_data_item(ITEM item);
/*
	in tat ca mat hang trong danh sach
*/
void print_all_item(LIST l );
/*
	dem so luong cac danh sach con
	dung mang luu tru so luong phan tu moi danh sach con
	gan gia tri mat dinh moi page la 15 phan tu
*/
void count_amount_list(int a[], int countlist, int &n);
/*
	dinh dang danh sach thanh cac page
*/
void format_list_item(LIST l, int countlist);
/*
	so sanh , kiem tra dieu kien tuy y cua so luong
*/
void listed_amount(LIST l, char *key, int amount_find);
/*
	liet ke danh sach
*/
void listed(LIST l, char *key, int count);
/*
	tim kiem
	return : NODE trong LIST
*/
NODE* Search_Item(LIST l, int code_item);
/*
	in du lieu da tim kiem
*/
void print_data_search(LIST l, int code_item);
/*
	nhap du lieu tu ban phim
*/
void setData(ITEM &item);
/*
	nhap du lieu vao file data.txt
*/
void input_file(LIST , int count);
/*
	them hoac cap nhap du lieu
	neu trung ma hang thi cap nhat lai so luong
	nguoc lai them vao cuoi danh sach
*/
void add_or_update_item(LIST &l, ITEM item, int &count);
/*
	cap nhat mat hang
*/
void update_item(LIST &l, ITEM &newitem, int count);
#endif
