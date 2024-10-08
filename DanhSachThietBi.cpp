#include "QuanLyThietBi.h"

void count_file(int &count){
	FILE *file = fopen("data.txt", "r");
	while(!feof(file)){
		char c = fgetc(file);
		if(c == '\n')
			count++;
	}
	count = (count + 1) / 9;
	fclose(file);

	
}
void init(LIST &l){
	l.pHead = l.pTail = NULL;
}
NODE* getNode(ITEM newItem){
	NODE *p = new NODE;
	if(p == NULL){
		return NULL;
	}
	else{
		p ->data = newItem;
		p ->pNext = NULL;
		return p;
	}
}
void addHead( LIST &l, ITEM item){
	NODE *p = getNode(item);
	if(l.pHead == NULL){
		l.pHead = l.pHead = p;
	}
	else{
		p ->pNext = l.pHead;
		l.pHead = p;	
	}
}
void addTail(LIST &l, ITEM item){
	NODE *p = getNode(item);
	if(l.pHead == NULL){
		l.pHead = l.pTail = p;
	}
	else{
		l.pTail ->pNext = p;
		l.pTail = p;
	}
}

int eof_or_line_break(char c) // kiem tra neu EOF hoac xuong hang
{
    return (c == '\n' || c == EOF);
}

void readline(char * line, int max_lengh, FILE *file)
{
    char c;
    int i = 0;
    while( !eof_or_line_break(c = fgetc(file)) && i < max_lengh - 1)
        line[i++] = c;
    line[i] = 0;

    if (i == max_lengh - 1) // neu line dai hon max_len
        while( (c = fgetc(file)) != '\n'); // bo het doan phia sau
            
}
void read_file_data(FILE *file, ITEM &item , LIST &l, int count){
	file = fopen("data.txt", "r");
	if(!file){
		printf("Coundn't find file 'data.txt'");
	}
	else{
		for(int i = 0; i < count; i++ ){
			char temp[MAX_SIZE];
			readline(temp, 15, file);
			item.code = atoi(temp);
		
			readline(item.name_item, 100, file);
		
			readline(temp, 100, file);
			item.price = (float)atoi(temp);
		
			readline(temp, 20, file);
			item.amount = atoi(temp);
			
			readline(temp, 20, file);
			item.amount_inventory = atoi(temp);
			
			readline(item.goods_condition, 20, file);
		
			readline(temp, 20, file);
			item.input_date.day = atoi(temp);
		
			readline(temp, 20, file);
			item.input_date.month = atoi(temp);
	
			readline(temp, 20, file);
			item.input_date.year = atoi(temp);
		
			addTail(l, item);
		
		}
	}
	fclose(file);
	
}
