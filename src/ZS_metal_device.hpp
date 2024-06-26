#ifndef ZS_METAL_DEVICE_hpp
#define ZS_METAL_DEVICE_hpp

/* --------------------------- */
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

/* --------------------------- */
#include <_ZS_smart_pointer.hpp>
#include <device_smart_pointer.hpp>
#include <ZS_md_profiler.hpp>
/* --------------------------- */

namespace ZS_metal_access {

class ZS_metal_device {
    public:
        ZS_metal_device();
        const device_smart_pointer& operator->() const { return _device; }
        ZS_md_profiler& profiler();
        friend class ZS_md_profiler;
    private:
        device_smart_pointer _device;
        _ZS_smart_pointer<MTL::CommandQueue> _queue;
        ZS_md_profiler _profiler;
//        _ZS_smart_pointer<MTL::CommandBuffer> _buffer;
};

}

#endif
