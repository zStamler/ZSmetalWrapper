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

void ZS_md_profiler::printArgumentBuffersTier() {
        std::vector<std::pair<MTL::ArgumentBuffersTier, std::string>> en {
            std::make_pair(MTL::ArgumentBuffersTier::ArgumentBuffersTier1, "ArgumentBuffersTier1"),
            std::make_pair(MTL::ArgumentBuffersTier::ArgumentBuffersTier2, "ArgumentBuffersTier2"),
        };
        for (auto& pr : en) {
                if (_device->argumentBuffersSupport() == pr.first) {
                        std::cout << pr.second << std::endl;
                }
        }
}

void ZS_md_profiler::printDeviceLocation() {
        std::vector<std::pair<MTL::DeviceLocation, std::string>> en {
            std::make_pair(MTL::DeviceLocation::DeviceLocationBuiltIn, "DeviceLocationBuiltIn"),
            std::make_pair(MTL::DeviceLocation::DeviceLocationSlot, "DeviceLocationSlot"),
            std::make_pair(MTL::DeviceLocation::DeviceLocationExternal, "DeviceLocationExternal"),
            std::make_pair(MTL::DeviceLocation::DeviceLocationUnspecified, "DeviceLocationUnspecified"),
        };
        for (auto& pr : en) {
                if (_device->location() == pr.first) {
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

void ZS_md_profiler::printPipelineOptions() {
        std::cout << "MTL::PipelineOptionNone, " <<
                "MTL::PipelineOptionArgumentInfo, " <<
                "MTL::PipelineOptionBufferTypeInfo, " << 
                "MTL::PipelineOptionFailOnBinaryArchiveMiss" << std::endl;
}

void ZS_md_profiler::printReadWriteTextureSupport() {
        std::vector<std::pair<MTL::ReadWriteTextureTier, std::string>> en {
            std::make_pair(MTL::ReadWriteTextureTier::ReadWriteTextureTierNone, "ReadWriteTextureTierNone"),
            std::make_pair(MTL::ReadWriteTextureTier::ReadWriteTextureTier1, "ReadWriteTextureTier1"),
            std::make_pair(MTL::ReadWriteTextureTier::ReadWriteTextureTier2, "ReadWriteTextureTier2")
        };
        for (auto& pr : en) {
                if (_device->readWriteTextureSupport() == pr.first) {
                        std::cout << pr.second << std::endl;
                }
        }
}

void ZS_md_profiler::printSparseTextureRegionAlignmentModeOptions() {
        std::cout << "SparseTextureRegionAlignmentModeOutward, " << 
            "SparseTextureRegionAlignmentModeInward" << std::endl;
}

void ZS_md_profiler::printLinearSize() {
        auto size = _device->maxThreadsPerThreadgroup();
        std::cout << size.width * size.height * size.depth << std::endl;
}

void ZS_md_profiler::printSize() {
        auto size = _device->maxThreadsPerThreadgroup();
        std::cout << size.width << " " << size.height << " " << size.depth << std::endl;
}

}














