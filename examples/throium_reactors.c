#include <mlogevo/everything.h>

void main() {
    for (int i=0;i<builtins.links;i++) {
        struct MlogObject reactor = getlink(i);
        if (reactor.type != builtins.thorium_reactor) {
            continue;
        }
        // Throium reactor has a cryofluid capacity of 30.0
        control_toggle(reactor, reactor.cryofluid > 10.0);
    }
}
