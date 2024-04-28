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
        // config checks
        void printArgumentBuffersTier();
        void printDeviceLocation();
        void printFamilySupportCheck();
        void printFeatureSetSupportCheck();
        void printPipelineOptions();
        void printReadWriteTextureSupport();
        void printSparseTextureRegionAlignmentModeOptions();
        // memory checks
        void printLinearSize();
        void printSize();
        template <typename T> const size_t maxRecommendedOfType();
    private:
        device_smart_pointer _device;
};

#ifndef ZSMDP_INLINES
#define ZSMDP_INLINES
template <typename T>
inline const size_t ZS_md_profiler::maxRecommendedOfType() {
        const auto szRaw = _device->recommendedMaxWorkingSetSize();
        return szRaw / sizeof(T);
}
#endif

}

#endif
