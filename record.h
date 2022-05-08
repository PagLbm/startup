#include <time.h>
#ifndef _RECORD_H
#define _RECORD_H

typedef struct consume_node{
	int vip_id;
	int goods_id;
	time_t time1;
	int money;
	struct consume_node*next;
}Record;

Record* Record_init(void);
void Record_add1(Record* start,int vip_id,int goods_id,int money);
void Record_add2(Record* start,Record* node);
void Record_print(Record*node);
void Record_list_print(Record*start);
void Record_destroy(Record*start);
Record* Record_copy(Record*ori);
Record* Record_list_copy(Record*ori);
Record* Record_sub_vip(Record*start,int id);
Record* Record_sub_goods(Record*start,int id);
Record* Record_sub_price(Record*start,int min,int max);
Record* Record_sub_time(Record*start,time_t min,time_t max);
long Record_addtotal_price(Record*start);
Record* Record_list_combine(Record* list1, Record* list2);
#endif
