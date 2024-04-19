#ifndef ZS_METAL_DEVICE_hpp
#define ZS_METAL_DEVICE_hpp

/* --------------------------- */
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

/* --------------------------- */
#include <_ZS_smart_pointer.hpp>
#include <device_smart_pointer.hpp>
/* --------------------------- */

namespace ZS_metal_access {

class ZS_metal_device {
    public:
        ZS_metal_device();
        const device_smart_pointer& operator->() const { return _device; }
        std::string name();
        void printSize();
        void printLinearSize();
        template <typename T> const size_t maxRecommendedOfType();
    private:
        device_smart_pointer _device;
        _ZS_smart_pointer<MTL::CommandQueue> _queue;
        _ZS_smart_pointer<MTL::CommandBuffer> _buffer;
};

#ifndef ZSMD_INLINES
#define ZSMD_INLINES
template <typename T>
inline const size_t ZS_metal_device::maxRecommendedOfType() {
        const auto szRaw = _device->recommendedMaxWorkingSetSize();
        return szRaw / sizeof(T);
}
#endif

}

#endif
