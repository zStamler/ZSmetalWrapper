#ifndef _SMART_POINTER_hpp
#define _SMART_POINTER_hpp

#include <iostream>
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
        _ZS_smart_pointer& operator=(const _ZS_smart_pointer& orig);
        _ZS_smart_pointer& operator=(T*&& orig) noexcept;
    protected:
        void _invisibleCopyCtor(const _ZS_smart_pointer& orig);
        void _invisibleDestructor();
        T* _device=nullptr;
        size_t* _refCount=nullptr;
};

#ifndef ZSP_INLINES
#define ZSP_INLINES

// constructors, destructors
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

// operator overloads
template <class T>
inline _ZS_smart_pointer<T>& _ZS_smart_pointer<T>::operator=(const _ZS_smart_pointer& orig) {
        if (this == &orig) { return *this; }
        _invisibleCopyCtor(orig);
        return *this;
}

template <class T>
inline _ZS_smart_pointer<T>& _ZS_smart_pointer<T>::operator=(T*&& orig) noexcept {
        std::swap(this->_device, orig);
        return *this;
}

#endif

}

#endif
