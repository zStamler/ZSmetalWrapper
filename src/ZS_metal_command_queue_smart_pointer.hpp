#ifndef METAL_COMMAND_QUEUE_SMART_POINTER_hpp
#define METAL_COMMAND_QUEUE_SMART_POINTER_hpp

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
/* --------------------------- */

namespace ZS_metal_access {

class ZS_metal_command_queue_smart_pointer : public _ZS_smart_pointer<MTL::CommandQueue> {
    public:
        ZS_metal_command_queue_smart_pointer(MTL::Device*);
        ~ZS_metal_command_queue_smart_pointer();
};

#ifndef ZSCQSP
#define ZSCQSP
// any templated inlines go here
inline ZS_metal_command_queue_smart_pointer::ZS_metal_command_queue_smart_pointer(MTL::Device* d) :
    _ZS_smart_pointer() {
        _device = d->newCommandQueue();
}

inline ZS_metal_command_queue_smart_pointer::~ZS_metal_command_queue_smart_pointer() {
        _invisibleDestructor();
        if (! *_refCount) {
                // destroy the command queue, if that's necessary or possible ..
        }
}
#endif



}

#endif
