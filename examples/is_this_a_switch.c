// yes, you can simply include "everything" instead
//#include <mlogevo/everything.h>

#include <mlogevo/mlog_object.h>
#include <mlogevo/mlog_builtins.h>
#include <mlogevo/io.h>
#include <mlogevo/block_control.h>

extern struct MlogObject message1;

void main() {
    for (int i=0;i<builtins.links;i++) {
        if (getlink(i).type == builtins.Switch) {
            //PRINT_STRING("Link #");
            //print_int(i);
            //PRINT_STRING(" is a switch\\n");
            // MlogEvo's first builtin function: print
            print("Link #", i, " is a switch.\n");
        }
    }
    print_flush(message1);
}
