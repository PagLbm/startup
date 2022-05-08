#include "record.h"
#include "vip.h"
#include "fun.h"
#include "goods.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void random_consume(Record* record_list, Vip* vip_list, Goods* goods_list){
	int vip_len=Vip_len(vip_list,1);
	int goods_len=Goods_len(goods_list,1);
	printf("###vip len %d\n",vip_len);
	printf("###goods len %d\n",goods_len);
	int vip_n,goods_n;
	vip_n=rand()%vip_len+1;
	goods_n=rand()%goods_len+1;
	printf("###choose vip %d\n",vip_n);
	printf("###choose goods %d\n",goods_n);
	Vip* vip=Vip_n_get(vip_list,vip_n);
	Goods* goods=Goods_n_get(goods_list,goods_n);
	if((vip->now)<(goods->price)){
		int charge=rand()%CHARGE_UNIT;
		vip->now+=CHARGE_UNIT+charge;
		vip->all+=CHARGE_UNIT+charge;
		Record_add1(record_list,vip->id,goods->id,CHARGE_UNIT+charge);
		return;
	}
	(vip->now)-=(goods->price);
	Record_add1(record_list,vip->id,goods->id,(-(goods->price)));
}
void vip_record_print(Record* record_list, Vip* vip){
	Record* sub=Record_sub_vip(record_list,vip->id);
	Record_list_print(sub);
	Record_destroy(sub);
}
void goods_record_print(Record* record_list, Goods* goods){
	Record* sub=Record_sub_goods(record_list,goods->id);
	Record_list_print(sub);
	Record_destroy(sub);
}

