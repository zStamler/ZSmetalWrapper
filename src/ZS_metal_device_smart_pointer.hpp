#ifndef METAL_DEVICE_SMART_POINTER_hpp
#define METAL_DEVICE_SMART_POINTER_hpp

/* --------------------------- */
#ifndef NS_PRIVATE_IMPLEMENTATION
#define NS_PRIVATE_IMPLEMENTATION
#endif

#ifndef CA_PRIVATE_IMPLEMENTATION 
#define CA_PRIVATE_IMPLEMENTATION
#endif

#ifndef MTL_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#endif

/* --------------------------- */
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

/* --------------------------- */
#include <_ZS_smart_pointer.hpp>
#include <ZS_metal_command_queue_smart_pointer.hpp>
/* --------------------------- */

namespace ZS_metal_access {

class ZS_metal_device_smart_pointer : public _ZS_smart_pointer<MTL::Device> {
    public:
        ZS_metal_device_smart_pointer();
        ~ZS_metal_device_smart_pointer();
        ZS_metal_device_smart_pointer(const ZS_metal_device_smart_pointer& orig);
        ZS_metal_command_queue_smart_pointer newCommandQueue();
        void printSize();
        void printLinearSize();
        template <typename T>
        const size_t maxRecommendedOfType();
};

#ifndef ZSMDSP
#define ZSMDSP
template <typename T>
inline const size_t ZS_metal_device_smart_pointer::maxRecommendedOfType() {
        const auto szRaw = _device->recommendedMaxWorkingSetSize();
        return szRaw / sizeof(T);
}

inline ZS_metal_device_smart_pointer::ZS_metal_device_smart_pointer
    (const ZS_metal_device_smart_pointer& orig) {
        _invisibleCopyCtor(orig);
}

inline ZS_metal_device_smart_pointer::ZS_metal_device_smart_pointer() {
        _device = MTL::CreateSystemDefaultDevice();
}

inline ZS_metal_device_smart_pointer::~ZS_metal_device_smart_pointer() {
        _invisibleDestructor();
        if (! *_refCount) {
                _device->release();
        }
}

inline void ZS_metal_device_smart_pointer::printSize() {
        auto size = _device->maxThreadsPerThreadgroup();
        std::cout << size.width << " " << size.height << " " << size.depth << std::endl;
}

inline void ZS_metal_device_smart_pointer::printLinearSize() {
        auto size = _device->maxThreadsPerThreadgroup();
        std::cout << size.width * size.height * size.depth << std::endl;
}
        
inline ZS_metal_command_queue_smart_pointer ZS_metal_device_smart_pointer::newCommandQueue() {
        return ZS_metal_command_queue_smart_pointer(_device);
}
#endif

}
#endif
