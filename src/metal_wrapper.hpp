#ifndef METAL_WRAPPER_hpp
#define METAL_WRAPPER_hpp

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
#include <ZS_metal_device_smart_pointer.hpp>
#include <ZS_metal_command_queue_smart_pointer.hpp>
/* --------------------------- */

namespace ZS_metal_access {

typedef ZS_metal_device_smart_pointer mdsp;
typedef ZS_metal_command_queue_smart_pointer mcqsp;

}

#endif
