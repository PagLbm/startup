#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "goods.h"
Goods* Goods_init(void){
	printf("#goods list init\n");
	Goods* start=(Goods*)malloc(sizeof(Goods));
	if(start==NULL){
		printf("#Goods list init error\n");
		exit(0);
	}
	start->id=0;
	start->next=NULL;
	return start;
}
void Goods_add1(Goods*start,char*name,int price){
	Goods* node=(Goods*)malloc(sizeof(Goods));
	if(node==NULL){
		printf("#Goods list add error\n");
		exit(0);
	}
	(start->id)++;
	node->id=start->id;
	node->next=NULL;
	strncpy(node->name,name,GOODS_NAME_LEN-1);
	node->price=price;
	Goods* p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=node;
	printf("#goods list add\n");
	Goods_print(node);
}
void Goods_add2(Goods*start,Goods*node){
	Goods* p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=node;
}
void Goods_destroy(Goods*start){
	Goods *p1,*p2;
	p1=start;
	do{
		p2=p1->next;
		free(p1);
		p1=p2;
	}while(p1!=NULL);
	printf("#Goods list destroy succ\n");
}
void Goods_print(Goods*node){
	printf("id %5d, name %s, price %d\n",node->id,node->name,node->price);
}
void Goods_list_print(Goods*start){
	printf("#goods list print\n");
	Goods*p=start;
	while(p->next!=NULL){
		p=p->next;
		Goods_print(p);
	}
}
Goods* Goods_copy(Goods*ori){
	Goods* bak=(Goods*)malloc(sizeof(Goods));
	if(bak==NULL){
		exit(0);
	}
	bak->id=ori->id;
	bak->price=ori->price;
	strcpy(bak->name,ori->name);
	bak->next=NULL;
	return bak;
}
Goods* Goods_list_copy(Goods*ori){
	Goods* new_list=Goods_copy(ori);
	new_list->next=NULL;
	Goods* point=ori;
	Goods* temp_node;
	while(point->next!=NULL){
		point=point->next;
		temp_node=Goods_copy(point);
		Goods_add2(new_list,temp_node);
	}
	printf("#Goods list copy\n");
	return new_list;
}
Goods* Goods_n_get(Goods*start,int n){
	if(n<1||n>Goods_len(start,0))
		return NULL;
	Goods*p=start;
	for(int count=0;count<n;count++)
		p=p->next;
	return p;
}
int Goods_len(Goods*start,int flag){
	if(flag==0)
		return start->id;
	Goods* p=start;
	int len=0;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	start->id=len;
	return len;
}
