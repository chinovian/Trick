/*
 @file
 $Id: MemoryManager_ref_var.cpp 1981 2011-10-13 14:43:54Z dstrauss $
 */
#include <string.h>
#include <stdio.h>
#include "sim_services/MemoryManager/include/MemoryManager.hh"
#include "sim_services/MemoryManager/include/value.h"
#include "sim_services/MemoryManager/include/vval.h"

int Trick::MemoryManager::ref_var( REF2* R,
                                   char* name) {

    ALLOC_INFO *alloc_info;
    VARIABLE_MAP::iterator pos;

    pthread_mutex_lock(&mm_mutex);
    pos = variable_map.find( name);
    if (pos != variable_map.end()) {
        alloc_info = pos->second;
        R->attr = make_reference_attr( alloc_info);
        R->address = alloc_info->start;
        
        if ( R->create_add_path ) {
            ADDRESS_NODE * address_node ;

            address_node = new ADDRESS_NODE ;
            address_node->operator_ = AO_ADDRESS ;
            address_node->operand.address = R->address ;
            DLL_AddTail(address_node , R->address_path) ;
        }

        pthread_mutex_unlock(&mm_mutex);
        return (MM_OK);
    } else {
        // ERROR. 
    }
    pthread_mutex_unlock(&mm_mutex);

    return (MM_UNDEFINED_REFERENCE);
}
