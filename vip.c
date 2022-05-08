#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"vip.h"
//vip链表初始化
Vip* Vip_init(void){
	Vip* start=(Vip*)malloc(sizeof(Vip));
	if(start==NULL){
		printf("#init Vip list error\n");
		exit(0);
	}
	start->next=NULL;
	start->id=0;
	printf("#init Vip list\n");
	return start;
}
//vip链表的长度
int Vip_len(Vip*start,int flag){
	if(flag==0)
		return start->id;
	Vip* p=start;
	int len=0;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	start->id=len;
	return len;
}

//在vip链表中添加结点,输入节点每个域的值
void Vip_add1(Vip* start,char* name,char* phone_number){
	Vip *p=start;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=(Vip*)malloc(sizeof(Vip));
	if(p->next==NULL){
		printf("#add new Vip error\n");
		exit(0);
	}
	p=p->next;
	start->id++;
	p->next=NULL;
	p->id=Vip_len(start,0);
	strncpy(p->name,name,LEN_NAME-1);
	p->all=0;
	p->now=0;
	strncpy(p->phone_number,phone_number,LEN_PHONE-1);
	printf("#vip add succ\n");
	Vip_print(p);
}
//在vip链表中添加结点,输入待加入节点的指针
void Vip_add2(Vip* start,Vip* node){
	Vip*p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=node;
	(p->next)->next=NULL;
}
//vip链表的销毁
void Vip_destroy(Vip*start){
	Vip *p1,*p2;
	p1=start;
	do{
		p2=p1->next;
		free(p1);
		p1=p2;
	}while(p1!=NULL);
	printf("#Vip list destroy succ\n");
}
void Vip_print(Vip*node){
	printf("id %d, name %s, now %d, phone_number %s\n",node->id,node->name,node->now,node->phone_number);
}
//打印全部vip信息
void Vip_list_print(Vip*start){
	printf("#Vip list print\n");
	Vip*p=start;
	while(p->next!=NULL){
		p=p->next;
		Vip_print(p);
	}
}
Vip* Vip_n_get(Vip*start,int n){
	if(n<1||n>Vip_len(start,0))
		return NULL;
	Vip*p=start;
	for(int count=0;count<n;count++)
		p=p->next;
	return p;
}
//复制单个节点
Vip* Vip_copy(Vip* ori){
	Vip* bak=(Vip*)malloc(sizeof(Vip));
	if(bak==NULL){
		printf("copy vip error\n");
		exit(0);
	}
	bak->next=ori->next;
	bak->id=ori->id;
	bak->now=ori->now;
	bak->all=ori->all;
	strncpy(bak->name,ori->name,LEN_NAME-1);
	strncpy(bak->phone_number,ori->phone_number,LEN_PHONE-1);
	return bak;
}
//复制整个链表
Vip* Vip_list_copy(Vip* ori){
	Vip* new_list=Vip_copy(ori);
	new_list->next=NULL;
	Vip* point=ori;
	Vip* temp_node;
	while(point->next!=NULL){
		point=point->next;
		temp_node=Vip_copy(point);
		Vip_add2(new_list,temp_node);
	}
	printf("#vip list copy\n");
	return new_list;
}
/*int Vip_list_saveload(Vip*start,char*name,int flag){
	FILE*fp;
	Vip*p=start;
	if(flag==0){
		fp=fopen(name,"w");
		if(fp==NULL){
			printf("#vip list save error\n");
			exit(0);
		}
		fprintf(fp,"#start\n");
		while(p->next!=NULL){
			p=p->next;
			fprintf(fp,"#vip\n");
	}
	fp=fopen(name,"r");
	if(fp==NULL){
		printf("#vip list load error\n");
		return 1;
	}
*/





