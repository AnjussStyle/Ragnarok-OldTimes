// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "../common/core.h"
#include "../common/socket.h"
#include "../common/timer.h"
#include "../common/mmo.h"
#include "../common/version.h"
#include "../common/db.h"
#include "../common/mapindex.h"

#ifndef _CHAR_H_
#define _CHAR_H_

#define START_CHAR_NUM 150000
#define MAX_MAP_SERVERS 30

#define LAN_CONF_NAME	"conf/subnet_athena.conf"

#define DEFAULT_AUTOSAVE_INTERVAL 300*1000

struct mmo_map_server{
  long ip;
  short port;
  int users;
  unsigned short map[MAX_MAP_PER_SERVER];
};
struct itemtmp {
	int flag;//checked = 1 else 0
	int id;
	short nameid;
	short amount;
	unsigned short equip;
	char identify;
	char refine;
	char attribute;
	short card[4];
};
enum {
	TABLE_INVENTORY,
	TABLE_CART,
	TABLE_STORAGE,
	TABLE_GUILD_STORAGE,
};
struct itemtemp{
	struct itemtmp equip[MAX_GUILD_STORAGE],notequip[MAX_GUILD_STORAGE];
};
int memitemdata_to_sql(struct itemtmp mapitem[], int count, int char_id,int tableswitch);

//int memitemdataNEW_to_sql(struct itemtmp mapitem[], int count, int char_id,int tableswitch);
int mapif_sendall(unsigned char *buf,unsigned int len);
int mapif_sendallwos(int fd,unsigned char *buf,unsigned int len);
int mapif_send(int fd,unsigned char *buf,unsigned int len);

int char_nick2id (char *name);
int char_married(int pl1,int pl2);
int char_child(int parent_id, int child_id);

int request_accreg2(int account_id, int char_id);
int save_accreg2(unsigned char* buf, int len);

extern bool char_gm_read;
extern int autosave_interval;
extern int save_log;
extern int charsave_method;
extern char db_path[];
extern char char_db[256];
extern char scdata_db[256];
extern char cart_db[256];
extern char inventory_db[256];
extern char charlog_db[256];
extern char storage_db[256];
extern char interlog_db[256];
extern char reg_db[256];
extern char skill_db[256];
extern char memo_db[256];
extern char guild_db[256];
extern char guild_alliance_db[256];
extern char guild_castle_db[256];
extern char guild_expulsion_db[256];
extern char guild_member_db[256];
extern char guild_position_db[256];
extern char guild_skill_db[256];
extern char guild_storage_db[256];
extern char party_db[256];
extern char pet_db[256];

extern int db_use_sqldbs; // added for sql item_db read for char server [Valaris]
extern int connection_ping_interval;

extern char login_db_level[32];
extern char login_db_account_id[32];

extern int lowest_gm_level;
extern int GM_num;
extern struct gm_account *gm_account;

extern int debug_mysql_query(char *file, int line, void *mysql, const char *q);

#endif

#include "inter.h"
#include "int_pet.h"
#include "int_guild.h"
#include "int_party.h"
#include "int_storage.h"
