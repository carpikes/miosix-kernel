#include "mpu/cortexMx_mpu.h"
#include "drivers/pll.h"

extern "C" void SystemInit();

namespace miosix {

void IRQmemoryAndClockInit()
{
    // Currently we use the code provided by ST (with our modifications) to
    // handle the memory and clock initialization process.
    SystemInit();

    startPll();
    
    // Architecture has MPU, enable kernel-level W^X protection
    IRQconfigureMPU();
}

} // namespace miosix
