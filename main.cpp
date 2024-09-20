#include "QuanLyThietBi.h"
#include <windows.h>

void menu(){
	printf("\n%95s\n\n", "_______CHUONG TRINH QUANG LY THIET BI , PHU KIEN MAY TINH_______");
	printf("\t\t\t\t\t\t\t*********\n");
	printf("%85s\n", " CHON CHUC NANG DE THUC HIEN CHUONG TRINH\n ");
	printf("\t\t\t\t\t\t|1. Add item\n");
	printf("\t\t\t\t\t\t|2. List\n");
	printf("\t\t\t\t\t\t|3. Search\n");
	printf("\t\t\t\t\t\t|4. Update item\n");
	printf("\t\t\t\t\t\t|5. Quit\n");


}
void color(int x){
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
       
}
int main(int argc, char *argv[]){
	
	//-------------------------------------------
	//count : bien dem so luong cac item trong file ;
	int count = 0;
	LIST l;
	ITEM item;
	FILE *file;
	//-------------------------------------------

	//-------------------------------------------
	count_file(count);
	init(l);
	read_file_data(file, item, l, count);
	//-------------------------------------------
	
	char temp[MAX_SIZE];
	int key;
	do{
		ITEM newitem1;
		ITEM newitem2;
		char find[MAX_SIZE];
		int code;
		char c;
		system("cls");
		color(10);
    	
		menu();
		printf("%52s", "key : ");
		scanf("%s", &temp);
		if(temp[0] <= 'A' && temp[0] >= 'Z' || temp[0] <= 'a' && temp[0] >= 'z')
			continue;
		else
	 		key = atoi(temp);
		switch(key){
			case 1: 
				system("cls");
				add_or_update_item(l, newitem1, count);
				break;
			case 2:
				system("cls");
				printf("*Note*\n");
				printf("---------------------------------------------------------------------------\n");
				printf("Key find : *tu khoa liet ke* + *phep so sanh* + *so luong so sanh* || 'all'\n\n");
				printf(" - tu khoa liet ke : 'so luong','SO LUONG', 'sl', 'SL' ,'amount', 'AMOUNT'\n");
				printf(" - phep so sanh : '>', '<', 'lon hon' , 'nho hon'\n");
				printf(" - so luong so sanh : nam trong kieu Integer\n");
				printf("---------------------------------------------------------------------------\n\n");
				fflush(stdin);
				printf("key find : ");
				gets(find);
				system("cls");
				
				listed(l, find, count);
				break;
			case 3:
				system("cls");
				printf("code : ");
				scanf("%d", &code);
				print_data_search(l, code);
				printf("\t\t\t\t\t\tq : MAIN MENU\n");
				fflush(stdin);
				printf("key : ");
				while(true){
					scanf("%c", &c);
					if(c == 'q')
						break;
				}
				break;
			case 4:
				system("cls");
				update_item(l, newitem2, count);
				printf("\t\t\t\t\t\tq : MAIN MENU\n");
				fflush(stdin);
				printf("key : ");
				while(true){
					scanf("%c", &c);
					if(c == 'q')
						break;
				}
				break;
		}
		if(key == 5)
			break;
		
	}
	while(true);
	
	_getch();
	return 0;
}
