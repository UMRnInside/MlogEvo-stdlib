// yes, you can simply include "everything" instead
//#include <mlogevo/everything.h>

#include <mlogevo/mlog_object.h>
#include <mlogevo/mlog_builtins.h>
#include <mlogevo/io.h>
#include <mlogevo/block_control.h>

extern struct MlogObject message1;

void main() {
    for (int i=0;i<builtins.links;i++) {
        struct MlogObject target = getlink(i);
        if (target == message1) {
            continue;
        }
        if (target.type == builtins.Switch) {
            PRINT_STRING("Link #");
            print_int(i);
            PRINT_STRING(" is a switch\\n");
        }
    }
    print_flush(message1);
}
