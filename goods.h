
#ifndef _GOODS_H
#define _GOODS_H
#define GOODS_NAME_LEN 20
typedef struct goods_node{
	int id;
	char name[GOODS_NAME_LEN];
	int price;
	struct goods_node *next;
}Goods;
Goods* Goods_init(void);
void Goods_add1(Goods*start,char*name,int price);
void Goods_add2(Goods*start,Goods*node);
void Goods_destroy(Goods*start);
void Goods_print(Goods*node);
void Goods_list_print(Goods*list);
Goods* Goods_copy(Goods*ori);
Goods* Goods_list_copy(Goods*start);
Goods* Goods_list_cut(Goods*ori,int i,int j);
Goods* Goods_n_get(Goods*start,int n);
int Goods_len(Goods*start,int flag);
Goods* Goods_list_saveload(Goods*start,char*name);
#endif
