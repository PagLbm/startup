#ifndef _VIP_H
#define _VIP_H

#define LEN_NAME 20
#define LEN_PHONE 20

typedef struct vip_node{
	int id;
	char name[LEN_NAME];
	int all;
	int now;
	char phone_number[LEN_PHONE];
	struct vip_node *next;
}Vip;

Vip* Vip_init(void);
int Vip_len(Vip*start,int flag);
void Vip_add1(Vip* start,char* name,char* phone_number);
void Vip_add2(Vip* start,Vip* node);
void Vip_destroy(Vip* start);
void Vip_print(Vip* node);
void Vip_list_print(Vip* start);
Vip* Vip_n_get(Vip* start,int n);
Vip* Vip_copy(Vip* ori);
Vip* Vip_list_copy(Vip* ori);
Vip* Vip_list_cut(Vip* ori,int i,int j);
Vip* Vip_list_saveload(Vip*start,char*name);
#endif
