#include "riscvfunc.h"

namespace rv
{
    RVAsms *GenAsms()
    {
        RVAsms *rvAsms = new RVAsms();
        return rvAsms;
    }
}