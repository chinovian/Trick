/*
 * $Id: vval.h 401 2009-11-13 20:21:13Z wwoodard $
 */

#ifndef VVAL_H
#define VVAL_H

#include "sim_services/MemoryManager/include/var.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Function prototypes
 */
char vval_char(V_DATA * V);
short vval_short(V_DATA * V);
int vval_int(V_DATA * V);
long vval_long(V_DATA * V);
long long vval_longlong(V_DATA * V);
float vval_float(V_DATA * V);
double vval_double(V_DATA * V);
char *vval_string(V_DATA * V);

#ifndef __Lynx__
wchar_t vval_wchar(V_DATA * V);
wchar_t *vval_wstring(V_DATA * V);
#else
int vval_wchar(V_DATA * V);
int *vval_wstring(V_DATA * V);
#endif

FILE *vval_filep(V_DATA * V);
void *vval_voidp(V_DATA * V);

/**
 * Recursively delete the given v_tree.
 * @param v_tree value tree.
 */
void delete_v_tree(V_TREE* v_tree);

#ifdef __cplusplus
}
#endif
#endif
