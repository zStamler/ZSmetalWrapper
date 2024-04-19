#ifndef METAL_DEVICE_SMART_POINTER_hpp
#define METAL_DEVICE_SMART_POINTER_hpp

/* --------------------------- */
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

/* --------------------------- */
#include <_ZS_smart_pointer.hpp>
/* --------------------------- */

namespace ZS_metal_access {

class device_smart_pointer : public _ZS_smart_pointer<MTL::Device> {
    public:
        device_smart_pointer();
        ~device_smart_pointer();
        device_smart_pointer(const device_smart_pointer& orig);
};

#ifndef DSP_INLINES
#define DSP_INLINES

inline device_smart_pointer::device_smart_pointer
    (const device_smart_pointer& orig) {
        _invisibleCopyCtor(orig);
}

inline device_smart_pointer::device_smart_pointer() {
        _device = MTL::CreateSystemDefaultDevice();
}

inline device_smart_pointer::~device_smart_pointer() {
        _invisibleDestructor();
        if (! *_refCount) {
                _device->release();
        }
}

#endif

}
#endif
