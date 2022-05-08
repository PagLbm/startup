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
	node->next=NULL;
	start->id++;
}
void Goods_destroy(Goods*start){
	if(start==NULL)
		return;
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
	if(node==NULL)
		return;
	printf("id %5d, name %s, price %d\n",node->id,node->name,node->price);
}
void Goods_list_print(Goods*start){
	if(start==NULL)
		return;
	printf("#goods list print\n");
	Goods*p=start;
	while(p->next!=NULL){
		p=p->next;
		Goods_print(p);
	}
}
Goods* Goods_copy(Goods*ori){
	if(ori==NULL)
		return NULL;
	Goods* bak=(Goods*)malloc(sizeof(Goods));
	if(bak==NULL){
		exit(0);
	}
	bak->id=ori->id;
	bak->price=ori->price;
	strncpy(bak->name,ori->name,GOODS_NAME_LEN-1);
	bak->next=NULL;
	return bak;
}
Goods* Goods_list_copy(Goods*ori){
	if(ori==NULL)
		return NULL;
	Goods* new_list=Goods_copy(ori);
	new_list->next=NULL;
	Goods* point=ori;
	Goods* temp_node;
	while(point->next!=NULL){
		point=point->next;
		temp_node=Goods_copy(point);
		Goods_add2(new_list,temp_node);
	}
	Goods_len(new_list,1);
	printf("#Goods list copy\n");
	return new_list;
}
Goods* Goods_list_cut(Goods*ori,int i,int j){
	int goods_len=Goods_len(ori,1);
	if(i<1||i>goods_len||j<i)
		return NULL;
	Goods* new_list=Goods_init();
	Goods *p1,*p2,*p3,*p4;
	p1=p3=ori;
	p2=p4=ori->next;
	for(int x=1;x<i;x++){
		p1=p1->next;
		p2=p2->next;
	}
	for(int x=0;x<j;x++){
		if(p4==NULL)
			break;
		p3=p3->next;
		p4=p4->next;
	}
	new_list->next=p2;
	p3->next=NULL;
	p1->next=p4;
	Goods_len(ori,1);
	Goods_len(new_list,1);
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
Goods* Goods_list_saveload(Goods*start,char*name){
	FILE*fp;
	if(start!=NULL){
		fp=fopen(name,"w");
		if(fp==NULL){
			printf("#goods list save error\n");
			exit(0);
		}
		int len=1+Goods_len(start,1);
		fprintf(fp,"%d\n",len);
		Goods*p=start;
		for(int i=0;i<len;i++){
			fwrite(p,sizeof(Goods),1,fp);
			p=p->next;
		}
		fclose(fp);
		return start;
	}
	else{
		fp=fopen(name,"r");
		if(fp==NULL){
			printf("#goods list load error\n");
			exit(0);
		}
		Goods* new_list=malloc(sizeof(Goods));
		int len;
		fscanf(fp,"%d\n",&len);
		fread(new_list,sizeof(Goods),1,fp);
		new_list->next=NULL;
		Goods*node;
		for(int i=1;i<len;i++){
			node=malloc(sizeof(Goods));
			if(node==NULL){
				exit(0);
			}
			fread(node,sizeof(Goods),1,fp);
			Goods_add2(new_list,node);
		}
		fclose(fp);
		return new_list;
	}
	return NULL;
}
