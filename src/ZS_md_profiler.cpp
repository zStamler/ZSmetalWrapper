/* --------------------------- */
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

/* --------------------------- */
#include <ZS_md_profiler.hpp>
#include <ZS_metal_device.hpp>
/* --------------------------- */

namespace ZS_metal_access {

ZS_md_profiler::ZS_md_profiler(ZS_metal_device* dv) : _device(dv->_device) {}

void ZS_md_profiler::printFeatureSetSupportCheck() {
        std::vector<std::pair<MTL::FeatureSet, std::string>> en {
            std::make_pair(MTL::FeatureSet::FeatureSet_macOS_GPUFamily1_v3, "FeatureSet_macOS_GPUFamily1_v3"),
            std::make_pair(MTL::FeatureSet::FeatureSet_macOS_GPUFamily1_v4, "FeatureSet_macOS_GPUFamily1_v4"),
            std::make_pair(MTL::FeatureSet::FeatureSet_macOS_GPUFamily2_v1, "FeatureSet_macOS_GPUFamily2_v1"),
            std::make_pair(MTL::FeatureSet::FeatureSet_watchOS_GPUFamily1_v1, "FeatureSet_watchOS_GPUFamily1_v1"),
            std::make_pair(MTL::FeatureSet::FeatureSet_WatchOS_GPUFamily1_v1, "FeatureSet_WatchOS_GPUFamily1_v1"),
            std::make_pair(MTL::FeatureSet::FeatureSet_watchOS_GPUFamily2_v1, "FeatureSet_watchOS_GPUFamily2_v1"),
            std::make_pair(MTL::FeatureSet::FeatureSet_WatchOS_GPUFamily2_v1, "FeatureSet_WatchOS_GPUFamily2_v1"),
            std::make_pair(MTL::FeatureSet::FeatureSet_tvOS_GPUFamily1_v1, "FeatureSet_tvOS_GPUFamily1_v1"),
            std::make_pair(MTL::FeatureSet::FeatureSet_TVOS_GPUFamily1_v1, "FeatureSet_TVOS_GPUFamily1_v1"),
            std::make_pair(MTL::FeatureSet::FeatureSet_tvOS_GPUFamily1_v2, "FeatureSet_tvOS_GPUFamily1_v2"),
            std::make_pair(MTL::FeatureSet::FeatureSet_tvOS_GPUFamily1_v3, "FeatureSet_tvOS_GPUFamily1_v3"),
            std::make_pair(MTL::FeatureSet::FeatureSet_tvOS_GPUFamily2_v1, "FeatureSet_tvOS_GPUFamily2_v1"),
            std::make_pair(MTL::FeatureSet::FeatureSet_tvOS_GPUFamily1_v4, "FeatureSet_tvOS_GPUFamily1_v4"),
            std::make_pair(MTL::FeatureSet::FeatureSet_tvOS_GPUFamily2_v2, "FeatureSet_tvOS_GPUFamily2_v2")
        };
        for (auto& pr : en) {
                if (_device->supportsFeatureSet(pr.first)) {
                        std::cout << pr.second << std::endl;
                }
        }
}

void ZS_md_profiler::printFamilySupportCheck() {
        std::vector<std::pair<MTL::GPUFamily, std::string>> en {
            std::make_pair(MTL::GPUFamily::GPUFamilyApple1, "GPUFamilyApple1"),
            std::make_pair(MTL::GPUFamily::GPUFamilyApple2, "GPUFamilyApple2"),
            std::make_pair(MTL::GPUFamily::GPUFamilyApple3, "GPUFamilyApple3"),
            std::make_pair(MTL::GPUFamily::GPUFamilyApple4, "GPUFamilyApple4"),
            std::make_pair(MTL::GPUFamily::GPUFamilyApple5, "GPUFamilyApple5"),
            std::make_pair(MTL::GPUFamily::GPUFamilyApple6, "GPUFamilyApple6"),
            std::make_pair(MTL::GPUFamily::GPUFamilyApple7, "GPUFamilyApple7"),
            std::make_pair(MTL::GPUFamily::GPUFamilyApple8, "GPUFamilyApple8"),
            std::make_pair(MTL::GPUFamily::GPUFamilyMac1, "GPUFamilyMac1"),
            std::make_pair(MTL::GPUFamily::GPUFamilyMac2, "GPUFamilyMac2"),
            std::make_pair(MTL::GPUFamily::GPUFamilyCommon1, "GPUFamilyCommon1"),
            std::make_pair(MTL::GPUFamily::GPUFamilyCommon2, "GPUFamilyCommon2"),
            std::make_pair(MTL::GPUFamily::GPUFamilyCommon3, "GPUFamilyCommon3"),
            std::make_pair(MTL::GPUFamily::GPUFamilyMacCatalyst1, "GPUFamilyMacCatalyst1"),
            std::make_pair(MTL::GPUFamily::GPUFamilyMacCatalyst2, "GPUFamilyMacCatalyst2")
        };
        for (auto& pr : en) {
                if (_device->supportsFamily(pr.first)) {
                        std::cout << pr.second << std::endl;
                }
        }
}

//_MTL_ENUM(NS::UInteger, DeviceLocation) {
//    DeviceLocationBuiltIn = 0,
//    DeviceLocationSlot = 1,
//    DeviceLocationExternal = 2,
//    DeviceLocationUnspecified = NS::UIntegerMax,
//};
//
//_MTL_OPTIONS(NS::UInteger, PipelineOption) {
//    PipelineOptionNone = 0,
//    PipelineOptionArgumentInfo = 1,
//    PipelineOptionBufferTypeInfo = 2,
//    PipelineOptionFailOnBinaryArchiveMiss = 4,
//};
//
//_MTL_ENUM(NS::UInteger, ReadWriteTextureTier) {
//    ReadWriteTextureTierNone = 0,
//    ReadWriteTextureTier1 = 1,
//    ReadWriteTextureTier2 = 2,
//};
//
//_MTL_ENUM(NS::UInteger, ArgumentBuffersTier) {
//    ArgumentBuffersTier1 = 0,
//    ArgumentBuffersTier2 = 1,
//};
//
//_MTL_ENUM(NS::UInteger, SparseTextureRegionAlignmentMode) {
//    SparseTextureRegionAlignmentModeOutward = 0,
//    SparseTextureRegionAlignmentModeInward = 1,
//};


}
