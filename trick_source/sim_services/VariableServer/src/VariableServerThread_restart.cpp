/*
 * $Id: VariableServerThread.cpp 3529 2014-05-15 15:04:03Z alin $
 */

#include <stdlib.h>
#include "sim_services/VariableServer/include/VariableServerThread.hh"

void Trick::VariableServerThread::preload_checkpoint() {
    // Let the thread complete any data copying it has to do
    // and then suspend data copying until the checkpoint is reloaded.
    pthread_mutex_lock(&copy_mutex);

    // Save the pause state of this thread.
    saved_pause_cmd = pause_cmd;

    // Disallow data writing.
    pause_cmd = true ;

    // Temporarily "disconnect" the variable references from Trick Managed Memory
    // by tagging each as a "bad reference".
    std::vector <VariableReference *>::iterator it ;
    for (it = vars.begin(); it != vars.end() ; it++) {
        (*it)->ref->address = (char*)&bad_ref_int;
        (*it)->ref->attr = new ATTRIBUTES() ;
        (*it)->ref->attr->type = TRICK_NUMBER_OF_TYPES ;
        (*it)->ref->attr->units = (char *)"--" ;
        (*it)->ref->attr->size = sizeof(int) ;
    }
}

void Trick::VariableServerThread::restart() {
    // Set the pause state of this thread back to its "pre-checkpoint reload" state.
    pause_cmd = saved_pause_cmd ;

    // Set retry_bad_ref so that variables in this varible server thread will
    // be re-resolved to the newly re-created memory objects.
    var_retry_bad_ref();

    // Allow data copying to continue.
    pthread_mutex_unlock(&copy_mutex);

}


