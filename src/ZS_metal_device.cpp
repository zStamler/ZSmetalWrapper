#include <ZS_metal_device.hpp>
#include <_ZS_smart_pointer.hpp>

namespace ZS_metal_access {

ZS_metal_device::ZS_metal_device() {
        _queue = _device->newCommandQueue();
        _buffer = _queue->commandBuffer();
}

std::string ZS_metal_device::name() {
        return "guy";
}

void ZS_metal_device::printSize() {
        auto size = _device->maxThreadsPerThreadgroup();
        std::cout << size.width << " " << size.height << " " << size.depth << std::endl;
}

void ZS_metal_device::printLinearSize() {
        auto size = _device->maxThreadsPerThreadgroup();
        std::cout << size.width * size.height * size.depth << std::endl;
}

}
