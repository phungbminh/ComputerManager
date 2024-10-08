#include "QuanLyThietBi.h"
#define MAX_LIST 15

void print_data_item(ITEM item){
	printf("%-5d %-30s %-15.1f %-15d %-20d %-15s %d/%d/%d\n", item.code, item.name_item,
	 item.price, item.amount, item.amount_inventory, item.goods_condition, 
	item.input_date.day, item.input_date.month, item.input_date.year);
}
void print_all_item(LIST l ){
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext){
		print_data_item(p ->data);
	}
}
void Heading(){
	printf("\n\t\t\t\t\tlIST OF COMPUTER EQUIPMEMT PRODUCTS\n\n");
	printf("---------------------------------------------------------------------------------------------------------------------\n");
	printf("%-5s %-30s %-15s %-15s %-20s %-15s %s\n", "Code", "Name item", 
	"Price", "Amount", "Amount Inventory", "Goods Condition", "Date");
	printf("---------------------------------------------------------------------------------------------------------------------\n");
	
}

void count_amount_list(int a[], int countlist, int &n){
	int dem = 0;
	int j = 0;
	int temp = countlist; //gan count cho temp luu gia tri count de chay vong lap 
	int i = 0;
	while(i < countlist	){
		dem++;
		if(dem == MAX_LIST){
			temp -= dem;
			a[j] = dem;
			j++;
			n++;
			dem = 0;
		}
		i++;	
	}
	if(temp != 0){
		a[j] = temp;
		n++;
	}		
}
void format_list_item(LIST l, int countlist){
	
	int a[MAX_SIZE]; // mang luu giu cac item cua moi danh sach con
	int n = 0; // so phan tu cua mang a
	int dem = 0;//dem so node de dung vong lap
	int i = 0; //index cua mang a;
	NODE *p = l.pHead; 
	count_amount_list(a, countlist, n);
	while(true){
		Heading();
		//xuat a[0] truoc
		while(p != NULL && dem < a[i]){
			print_data_item(p ->data);
			dem++;
			p = p ->pNext;
		}
		dem = 0;
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("\tb : BACK\t\t\t\tn : NEXT\t\t\t\tq : MAIN MENU\n");
		printf("\t\t\t\t\t\tPAGE[ %d|%d ]\n", i + 1, n);
		char c;
		printf("Key : ");
		while(true){
			scanf("%c", &c);
			if(c == 'n' || c == 'b' || c == 'q')
				break;
		}
		
		if(c == 'n'){
			system("cls");
			if(i <= n - 2)
				i++;
				//neu i la danh sach cuoi thi cho con tro p tro den dau danh sach truoc do
			if(i == n - 1){
				int x = 0;
				for(int j = 0; j <= n - 2; j++){
					x += a[j];
				}
				p = l.pHead;
				while(p != NULL && dem < x){
					p = p ->pNext;
					dem++;
				}
				dem = 0;
			}
		}
		if(c == 'b'){
			system("cls");
			if(i <= 1){
				p = l.pHead;
				i = 0;
			}
			else{
				int x = 0;
				for(int j = 0; j <= i - 2; j++){
					x += a[j];
				}
				p = l.pHead;
				while(p != NULL && dem < x){
					p = p ->pNext;
					dem++;
				}
				dem = 0;
				i--;
			}
		}
		if(c == 'q')
			return;
	}
}
void listed_amount(LIST l, char *key, int amount_find){
	int dem = 0;
	if(strstr(key, ">") != NULL || strstr(key, "lon hon") != NULL || strstr(key, "LON HON")){
		LIST l2;
		init(l2);
		for(NODE *p = l.pHead; p != NULL ; p = p ->pNext){
			if(p ->data.amount > amount_find){
				dem++;
				addTail(l2, p ->data);
			}
		}
		format_list_item(l2, dem);
	}
	if(strstr(key, "<") != NULL || strstr(key, "nho hon") != NULL){
		LIST l3;
		init(l3);
		for(NODE *p = l.pHead; p != NULL ; p = p ->pNext){
			if(p ->data.amount < amount_find){
				dem++;
				addTail(l3, p ->data);
			}
		}
		format_list_item(l3, dem);
	}
}
void listed(LIST l, char *key, int count){
	
	if(stricmp(key, "all") == 0)
		format_list_item(l, count);
	else{
		char str[MAX_SIZE];
		int amount_find;
		int index_str = 0;
		int j = 0;
		for(int i = 0;i < strlen(key); i++){
			if(key[i] >= '0' && key[i] <= '9'){
				for(int j = i ; j < strlen(key); j ++){
					str[index_str++] = key[j];
				}
				str[index_str ] = '\0';
				break;
			}
		}
		amount_find = atoi(str);
		if(strstr(key , "so luong") != NULL || strstr(key, "sl") != NULL || strstr(key , "SO LUONG") != NULL
		 || strstr(key, "SL") != NULL || strstr(key, "amount") != NULL || strstr(key, "AMOUNT") != NULL){
 			listed_amount(l, key, amount_find);
 		}
		else{
			printf("Invalid keywords\n");
			printf("\t\t\t\t\t\tq : MAIN MENU\n");
				fflush(stdin);
				printf("key : ");
				char c;
				while(true){
					scanf("%c", &c);
					if(c == 'q')
						break;
				}
		}
			
	}

}
NODE* Search_Item(LIST l, int code_item){
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext){
		if(p ->data.code == code_item){
			return p;
		}
	}
	return NULL;
}
void print_data_search(LIST l, int code_item){
	NODE *p = Search_Item(l, code_item);
	if(p != NULL){
		Heading();
		print_data_item(p->data);
		printf("---------------------------------------------------------------------------------------------------------------------\n");
	}
	else{
		printf("Coundn't find item !\n");
	}
}
void setData(ITEM &item){
	printf("Code : ");
	scanf("%d", &item.code);
	fflush(stdin);
	printf("Name item : ");
	gets(item.name_item);
	printf("Price : ");
	scanf("%f", &item.price);
	printf("Amount : ");
	scanf("%d", &item.amount);
	printf("Amoutnt inventory : ");
	scanf("%d", &item.amount_inventory);
	fflush(stdin);
	printf("Goods conditions : ");
	gets(item.goods_condition);
	printf("Date (dd/MM/yyyy) : ");
	scanf("%d/%d/%d",& item.input_date.day, &item.input_date.month, &item.input_date.year);
}
void input_file(LIST l, int count){//31
	int dem = 0;
	FILE *filein = fopen("data.txt", "w");
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext){
		fprintf(filein, "%d\n", p ->data.code);
		fprintf(filein, "%s\n", p ->data.name_item);
		fprintf(filein, "%.0f\n", p ->data.price);
		fprintf(filein, "%d\n", p ->data.amount);
		fprintf(filein, "%d\n", p ->data.amount_inventory);
		fprintf(filein, "%s\n", p ->data.goods_condition);
		fprintf(filein, "%d\n", p ->data.input_date.day);
		fprintf(filein, "%d\n", p ->data.input_date.month);
		fprintf(filein, "%d", p ->data.input_date.year);
		dem++;
		if(dem <= count){
			fprintf(filein ,"\n");
		}
	}
	fclose(filein);
}
void add_or_update_item(LIST &l, ITEM item, int &count){
	setData(item);
	if(Search_Item(l, item.code	) != NULL){
		Search_Item(l, item.code) ->data.amount += item.amount;
		input_file(l , count);
	}
	else{
		addTail(l, item);
		input_file( l, count);
		count++;
	}
}
void update_item(LIST &l, ITEM &newitem, int count){
	setData(newitem);
	
	NODE *p = Search_Item(l, newitem.code);
	if(p != NULL){
		strcpy(p ->data.name_item , newitem.name_item);
		p ->data.price = newitem.price;
		p ->data.amount = newitem.amount;
		p ->data.amount_inventory = newitem.amount_inventory;
		strcpy(p ->data.goods_condition, newitem.goods_condition);
		p ->data.input_date.day = newitem.input_date.day;
		p ->data.input_date.month = newitem.input_date.month;
		p ->data.input_date.year = newitem.input_date.year;
		input_file(l, count);
	}
	else
		printf("Item not found!\n");
}
