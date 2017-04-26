#ifndef _DAO_H
#define _DAO_H

#include "../inc/bank.h"

int dao_unique (void);
int dao_insert (const ACCOUNT* acc);
int dao_select (int id, ACCOUNT* acc);
int dao_update (const ACCOUNT* acc);
int dao_delete (int id);

#endif // _DAO_H
