#include "record.h"
#include "vip.h"
#include "goods.h"
#ifndef _FUN_H
#define _FUN_H
#define CHARGE_UNIT 500
void random_consume(Record* record_list, Vip* vip_list, Goods* goods_list);
void vip_record_print(Record* record_list, Vip* vip);
void goods_record_print(Record* record_list, Goods* goods);
#endif
