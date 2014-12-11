/***************************************************************************
 * 
 * Copyright (c) 2014 liudong9183@163.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file hash_table.h
 * @author liudong2(liudong9183@163.com)
 * @date 2014/12/11 21:31:06
 * @version $Revision$
 * @brief 
 *  
 **/



#ifndef  __HASH_TABLE_H_
#define  __HASH_TABLE_H_

typedef struct _hentry_t {
    char *key;
    void *val;
    hentry *next;
} hentry_t;

typedef void (*dup_val_func)(void *val);
typedef void (*free_val_func)(void *val);

typedef struct _htable_t {
    uint32_t size;
    hentry_t **data;
    uint32_t mask;
    dup_val_func pdup_func;
    free_val_func pfree_func;
} htable_t;

htable_t* init_htable(uint32_t bitsz, dup_val_func *dup_func, 
        free_val_func *free_func);
int32_t hset_val(htable_t *ht, char *k, void *val);
int32_t hdel_val(htable_t *ht, char *k);
int32_t destroy_htable(htable_t *ht);





#endif  //__HASH_TABLE_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
