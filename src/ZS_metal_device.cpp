/* --------------------------- */
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

/* --------------------------- */
#include <ZS_metal_device.hpp>
#include <ZS_md_profiler.hpp>
#include <_ZS_smart_pointer.hpp>

/* --------------------------- */

namespace ZS_metal_access {

ZS_metal_device::ZS_metal_device() : 
    _profiler(ZS_md_profiler(this)) 
{
        _queue = _device->newCommandQueue();
//        _buffer = _queue->commandBuffer();
}

ZS_md_profiler& ZS_metal_device::profiler() { return _profiler; }

}
