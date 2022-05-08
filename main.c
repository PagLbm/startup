#include <stdio.h>
#include "vip.h"
#include "record.h"
#include "fun.h"
int main(){
	Vip* vip_list=Vip_init();
	Record* record_list=Record_init();
	Goods* goods_list=Goods_init();

	Vip_add1(vip_list,"name_abc","ph_2834932874");
	Vip_add1(vip_list,"name_dds","ph_2349892618");
	Vip_add1(vip_list,"name_sid","ph_8274755773");
	Vip_add1(vip_list,"name_idd","ph_8923745324");
	Vip_add1(vip_list,"name_ddd","ph_8234558293");
	Vip_list_print(vip_list);

	Goods_add1(goods_list,"gname_8293",38);
	Goods_add1(goods_list,"gname_8223",138);
	Goods_add1(goods_list,"gname_8228",448);
	Goods_add1(goods_list,"gname_8229",238);
	Goods_add1(goods_list,"gname_7293",388);
	Goods_add1(goods_list,"gname_6293",32);
	Goods_add1(goods_list,"gname_9293",65);
	Goods_add1(goods_list,"gname_1293",99);
	Goods_add1(goods_list,"gname_2293",319);
	Goods_list_print(goods_list);

	int ch;
	while((ch=getchar())!='#')
		random_consume(record_list,vip_list,goods_list);
	Record_list_print(record_list);

	vip_record_print(record_list,Vip_n_get(vip_list,4));
	goods_record_print(record_list,Goods_n_get(goods_list,5));

	Record*temp1=Record_sub_vip(record_list,3);
	Record*temp2=Record_sub_vip(record_list,2);
	Record*temp=Record_list_combine(temp1,temp2);
	Record_list_print(temp);
	Record_destroy(temp);
	Record_destroy(temp1);
	Record_destroy(temp2);

	Record*t1=Record_sub_price(record_list,0,9999);
	Record_list_print(t1);
	Record*t2=Record_sub_vip(t1,2);
	Record_list_print(t2);
	printf("#all %ld\n",Record_addtotal_price(t2));
	Record_destroy(t1);
	Record_destroy(t2);

	Record_destroy(record_list);
	Vip_destroy(vip_list);
	Goods_destroy(goods_list);
	return 0;
}
