#ifndef ZS_MD_PROFILER_hpp
#define ZS_MD_PROFILER_hpp

/* --------------------------- */
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

/* --------------------------- */
#include <device_smart_pointer.hpp>
/* --------------------------- */

namespace ZS_metal_access {

class ZS_metal_device;

class ZS_md_profiler {
    public:
        ZS_md_profiler(ZS_metal_device* dv);
        void printFamilySupportCheck();
        void printFeatureSetSupportCheck();
    private:
        device_smart_pointer _device;
};

}

#endif
