/*
The MIT License (MIT)

Copyright (c) <2014> <oliver-lxtech2013@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASH_FAIL  -1

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
/*
  基本的Hash操作包括如下:
  1. 创建Hash表;
  2. 计算Hash;
  3. 释放Hash表;
  4. 往表中插入值;
  5. 从Hash表中查询值.
 */

template <class Object>
class HashTable
{
    private:
        typedef struct _list_t {
            string key;
            Object value;            /* satellite data */
            struct _list_t *next;    /* pointer to next list node */
        } list_t;

        list_t **table;                              /* pointer to table of elements */

        /* calculate hash value of string */
        unsigned int Hash(string str) {
            unsigned int hash_value = 0;
            int i = 0;
            for(; i < str.length(); i++) {
                hash_value = str[i] + (hash_value << 5) - hash_value;
            }
            return hash_value % TableSize;
        }

    public:
        int TableSize;                                    /* the number of key-value pair */
        HashTable(int tab_size) {
            table = (list_t **) calloc(tab_size, sizeof(list_t *));
            TableSize = tab_size;
        }

        virtual ~HashTable() {
            free(table);
        }

        /* insert a key value pair */
        void Add(string key, Object value) {
            /* find the same key */
            if(Contain(key))
                return;

            list_t *node = new list_t;      /* instance a new link node */
            node->key = key;                /* copy key */
            node->value = value;            /* copy value */

            unsigned int hash_val = Hash(key);    /* calculate key's hash value  */

            node->next = table[hash_val];              /* next point */
            table[hash_val] = node;

        }

        /* determine if the table contains one key */
        bool Contain(string key) {
            unsigned int hash_val = Hash(key);
            list_t *node = NULL;
            for(node = table[hash_val]; node != NULL; node = node->next) {
                if(key.compare(node->key) == 0)
                    return true;
            }
            return false;
        }

        /* look up key */
        Object LookUp(string key) {
            Object obj;
            unsigned int hash_val = Hash(key);
            list_t *node = NULL;
            for(node = table[hash_val]; node != NULL; node = node->next) {
                if(key.compare(node->key) == 0)
                    break;
            }

            return (node ? node->value : obj);         //TODO: Need return according to template
        }

};

#endif // HASHTABLE_H
