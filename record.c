#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"record.h"

Record* Record_init(void){
	Record* start=malloc(sizeof(Record));
	if(start==NULL){
		printf("init Record error\n");
		exit(0);
	}
	start->next=NULL;
	printf("#init Record list\n");
	return start;
}
void Record_add1(Record* start,int vip_id,int goods_id,int money){
	Record*p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=malloc(sizeof(Record));
	if(p->next==NULL){
		printf("add Record error\n");
		exit(0);
	}
	p=p->next;
	p->vip_id=vip_id;
	p->goods_id=goods_id;
	time(&(p->time1));
	p->money=money;
	p->next=NULL;
	printf("#record add succ\n");
	Record_print(p);
}
void Record_add2(Record* start,Record* node){
	Record*p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=node;
	(p->next)->next=NULL;
}
void Record_print(Record*p){
	printf("time:%ld, vip_id:%5d, goods_id:%5d, money:%d\n",p->time1,p->vip_id,p->goods_id,p->money);
}
void Record_list_print(Record*start){
	Record*p=start;
	printf("#Record list print\n");
	while(p->next!=NULL){
		p=p->next;
		Record_print(p);
	}
}
void Record_destroy(Record*start){
	Record *p1,*p2;
	p1=start;
	do{
		p2=p1->next;
		free(p1);
		p1=p2;
	}while(p1!=NULL);
	printf("#Record list destroy succ\n");
}
Record* Record_copy(Record*ori){
	Record*bak=malloc(sizeof(Record));
	if(bak==NULL){
		exit(0);
	}
	bak->next=NULL;
	bak->vip_id=ori->vip_id;
	bak->goods_id=ori->goods_id;
	bak->money=ori->money;
	bak->time1=ori->time1;
	return bak;
}
Record* Record_list_copy(Record*ori){
	Record* new_list=Record_copy(ori);
	new_list->next=NULL;
	Record*point=ori;
	Record*temp;
	while(point->next!=NULL){
		point=point->next;
		temp=Record_copy(point);
		Record_add2(new_list,temp);
	}
	printf("#record list copy\n");
	return new_list;
}
Record* Record_sub_vip(Record*start,int id){
	Record*sub=Record_init();
	Record*p=start;
	while(p->next!=NULL){
		p=p->next;
		if(p->vip_id==id)
			Record_add2(sub,Record_copy(p));
	}
	return sub;
}
Record* Record_sub_goods(Record*start,int id){
	Record*sub=Record_init();
	Record*p=start;
	while(p->next!=NULL){
		p=p->next;
		if(p->goods_id==id)
			Record_add2(sub,Record_copy(p));
	}
	return sub;
}
Record* Record_sub_price(Record*start,int min,int max){
	Record*sub=Record_init();
	Record*p=start;
	while(p->next!=NULL){
		p=p->next;
		if((p->money>min)&&(p->money<max))
			Record_add2(sub,Record_copy(p));
	}
	return sub;
}
Record* Record_sub_time(Record*start,time_t min,time_t max){
	Record*sub=Record_init();
	Record*p=start;
	while(p->next!=NULL){
		p=p->next;
		if((p->time1>min)&&(p->time1<max))
			Record_add2(sub,Record_copy(p));
	}
	return sub;
}
long Record_addtotal_price(Record*start){
	Record*p=start;
	long a=0;
	while(p->next!=NULL){
		p=p->next;
		a+=p->money;
	}
	return a;
}
Record* Record_list_combine(Record* list1, Record* list2){
	Record* new_list=Record_init();
	Record*p=list1;
	while(p->next!=NULL){
		p=p->next;
		Record_add2(new_list,Record_copy(p));
	}
	p=list2;
	while(p->next!=NULL){
		p=p->next;
		Record_add2(new_list,Record_copy(p));
	}
	return new_list;
}

