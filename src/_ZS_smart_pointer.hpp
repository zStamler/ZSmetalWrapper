#ifndef _SMART_POINTER_hpp
#define _SMART_POINTER_hpp

#include <iostream>

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

namespace ZS_metal_access {

// a parent class that contains the reference counting 
//      and direct access mechanisms
template <class T> class _ZS_smart_pointer {
    public:
        _ZS_smart_pointer();
        ~_ZS_smart_pointer();
        _ZS_smart_pointer(const _ZS_smart_pointer& orig) {
                _invisibleCopyCtor(orig);
        }
        T* operator->() const { return _device; }
        T& operator*() { return *_device; }
    protected:
        void _invisibleCopyCtor(const _ZS_smart_pointer& orig);
        void _invisibleDestructor();
        T* _device=nullptr;
        size_t* _refCount=nullptr;
};

#ifndef ZSP_INLINES
#define ZSP_INLINES
template <class T>
inline _ZS_smart_pointer<T>::_ZS_smart_pointer() {
        _refCount = new size_t; *_refCount = 1;
}

template <class T>
inline _ZS_smart_pointer<T>::~_ZS_smart_pointer() {
        if (! *_refCount) {
                delete _refCount;
        }
}

template <class T>
inline void _ZS_smart_pointer<T>::_invisibleCopyCtor(const _ZS_smart_pointer& orig) {
        this->_device = orig._device;
        this->_refCount = orig._refCount;
        ++(*_refCount);
}

template <class T>
inline void _ZS_smart_pointer<T>::_invisibleDestructor() {
        --(*_refCount);
}
#endif

}

#endif
