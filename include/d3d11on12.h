/*** Autogenerated by WIDL 5.0 from ./d3d11on12.idl - Do not edit ***/

#ifdef _WIN32
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include <rpc.h>
#include <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __d3d11on12_h__
#define __d3d11on12_h__

/* Forward declarations */

#ifndef __ID3D11On12Device_FWD_DEFINED__
#define __ID3D11On12Device_FWD_DEFINED__
typedef interface ID3D11On12Device ID3D11On12Device;
#ifdef __cplusplus
interface ID3D11On12Device;
#endif /* __cplusplus */
#endif

#ifndef __ID3D11On12Device1_FWD_DEFINED__
#define __ID3D11On12Device1_FWD_DEFINED__
typedef interface ID3D11On12Device1 ID3D11On12Device1;
#ifdef __cplusplus
interface ID3D11On12Device1;
#endif /* __cplusplus */
#endif

#ifndef __ID3D11On12Device2_FWD_DEFINED__
#define __ID3D11On12Device2_FWD_DEFINED__
typedef interface ID3D11On12Device2 ID3D11On12Device2;
#ifdef __cplusplus
interface ID3D11On12Device2;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <oaidl.h>
#include <ocidl.h>
#include <d3d11.h>
#include <d3d12.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <winapifamily.h>
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES)

///////////////////////////////////////////////////////////////////////////
// D3D11On12CreateDevice
// ------------------
//
// pDevice
//      Specifies a pre-existing D3D12 device to use for D3D11 interop.
//      May not be NULL.
// Flags
//      Any of those documented for D3D11CreateDeviceAndSwapChain.
// pFeatureLevels
//      Array of any of the following:
//          D3D_FEATURE_LEVEL_12_1
//          D3D_FEATURE_LEVEL_12_0
//          D3D_FEATURE_LEVEL_11_1
//          D3D_FEATURE_LEVEL_11_0
//          D3D_FEATURE_LEVEL_10_1
//          D3D_FEATURE_LEVEL_10_0
//          D3D_FEATURE_LEVEL_9_3
//          D3D_FEATURE_LEVEL_9_2
//          D3D_FEATURE_LEVEL_9_1
//       The first feature level which is less than or equal to the
//       D3D12 device's feature level will be used to perform D3D11 validation.
//       Creation will fail if no acceptable feature levels are provided.
//       Providing NULL will default to the D3D12 device's feature level.
// FeatureLevels
//      Size of feature levels array.
// ppCommandQueues
//      Array of unique queues for D3D11On12 to use. Valid queue types:
//          3D command queue.
//      Flags must be compatible with device flags, and its NodeMask must
//      be a subset of the NodeMask provided to this API.
// NumQueues
//      Size of command queue array.
// NodeMask
//      Which node of the D3D12 device to use.  Only 1 bit may be set.
// ppDevice
//      Pointer to returned interface. May be NULL.
// ppImmediateContext
//      Pointer to returned interface. May be NULL.
// pChosenFeatureLevel
//      Pointer to returned feature level. May be NULL.
//
// Return Values
//  Any of those documented for 
//          D3D11CreateDevice
//
///////////////////////////////////////////////////////////////////////////
typedef HRESULT (WINAPI* PFN_D3D11ON12_CREATE_DEVICE)( _In_ IUnknown*, UINT, 
    _In_reads_opt_( FeatureLevels ) CONST D3D_FEATURE_LEVEL*, UINT FeatureLevels, 
    _In_reads_opt_( NumQueues ) IUnknown* CONST*, UINT NumQueues, 
    UINT, _COM_Outptr_opt_ ID3D11Device**, _COM_Outptr_opt_ ID3D11DeviceContext**, 
    _Out_opt_ D3D_FEATURE_LEVEL* );

HRESULT WINAPI D3D11On12CreateDevice(
    _In_ IUnknown* pDevice,
    UINT Flags,
    _In_reads_opt_( FeatureLevels ) CONST D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    _In_reads_opt_( NumQueues ) IUnknown* CONST* ppCommandQueues,
    UINT NumQueues,
    UINT NodeMask,
    _COM_Outptr_opt_ ID3D11Device** ppDevice,
    _COM_Outptr_opt_ ID3D11DeviceContext** ppImmediateContext,
    _Out_opt_ D3D_FEATURE_LEVEL* pChosenFeatureLevel );

typedef struct D3D11_RESOURCE_FLAGS {
    UINT BindFlags;
    UINT MiscFlags;
    UINT CPUAccessFlags;
    UINT StructureByteStride;
} D3D11_RESOURCE_FLAGS;
/*****************************************************************************
 * ID3D11On12Device interface
 */
#ifndef __ID3D11On12Device_INTERFACE_DEFINED__
#define __ID3D11On12Device_INTERFACE_DEFINED__

DEFINE_GUID(IID_ID3D11On12Device, 0x85611e73, 0x70a9, 0x490e, 0x96,0x14, 0xa9,0xe3,0x02,0x77,0x79,0x04);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("85611e73-70a9-490e-9614-a9e302777904")
ID3D11On12Device : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE CreateWrappedResource(
        IUnknown *pResource12,
        const D3D11_RESOURCE_FLAGS *pFlags11,
        D3D12_RESOURCE_STATES InState,
        D3D12_RESOURCE_STATES OutState,
        REFIID riid,
        void **ppResource11) = 0;

    virtual void STDMETHODCALLTYPE ReleaseWrappedResources(
        ID3D11Resource *const *ppResources,
        UINT NumResources) = 0;

    virtual void STDMETHODCALLTYPE AcquireWrappedResources(
        ID3D11Resource *const *ppResources,
        UINT NumResources) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ID3D11On12Device, 0x85611e73, 0x70a9, 0x490e, 0x96,0x14, 0xa9,0xe3,0x02,0x77,0x79,0x04)
#endif
#else
typedef struct ID3D11On12DeviceVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ID3D11On12Device *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ID3D11On12Device *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ID3D11On12Device *This);

    /*** ID3D11On12Device methods ***/
    HRESULT (STDMETHODCALLTYPE *CreateWrappedResource)(
        ID3D11On12Device *This,
        IUnknown *pResource12,
        const D3D11_RESOURCE_FLAGS *pFlags11,
        D3D12_RESOURCE_STATES InState,
        D3D12_RESOURCE_STATES OutState,
        REFIID riid,
        void **ppResource11);

    void (STDMETHODCALLTYPE *ReleaseWrappedResources)(
        ID3D11On12Device *This,
        ID3D11Resource *const *ppResources,
        UINT NumResources);

    void (STDMETHODCALLTYPE *AcquireWrappedResources)(
        ID3D11On12Device *This,
        ID3D11Resource *const *ppResources,
        UINT NumResources);

    END_INTERFACE
} ID3D11On12DeviceVtbl;

interface ID3D11On12Device {
    CONST_VTBL ID3D11On12DeviceVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ID3D11On12Device_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ID3D11On12Device_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ID3D11On12Device_Release(This) (This)->lpVtbl->Release(This)
/*** ID3D11On12Device methods ***/
#define ID3D11On12Device_CreateWrappedResource(This,pResource12,pFlags11,InState,OutState,riid,ppResource11) (This)->lpVtbl->CreateWrappedResource(This,pResource12,pFlags11,InState,OutState,riid,ppResource11)
#define ID3D11On12Device_ReleaseWrappedResources(This,ppResources,NumResources) (This)->lpVtbl->ReleaseWrappedResources(This,ppResources,NumResources)
#define ID3D11On12Device_AcquireWrappedResources(This,ppResources,NumResources) (This)->lpVtbl->AcquireWrappedResources(This,ppResources,NumResources)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT ID3D11On12Device_QueryInterface(ID3D11On12Device* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG ID3D11On12Device_AddRef(ID3D11On12Device* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG ID3D11On12Device_Release(ID3D11On12Device* This) {
    return This->lpVtbl->Release(This);
}
/*** ID3D11On12Device methods ***/
static FORCEINLINE HRESULT ID3D11On12Device_CreateWrappedResource(ID3D11On12Device* This,IUnknown *pResource12,const D3D11_RESOURCE_FLAGS *pFlags11,D3D12_RESOURCE_STATES InState,D3D12_RESOURCE_STATES OutState,REFIID riid,void **ppResource11) {
    return This->lpVtbl->CreateWrappedResource(This,pResource12,pFlags11,InState,OutState,riid,ppResource11);
}
static FORCEINLINE void ID3D11On12Device_ReleaseWrappedResources(ID3D11On12Device* This,ID3D11Resource *const *ppResources,UINT NumResources) {
    This->lpVtbl->ReleaseWrappedResources(This,ppResources,NumResources);
}
static FORCEINLINE void ID3D11On12Device_AcquireWrappedResources(ID3D11On12Device* This,ID3D11Resource *const *ppResources,UINT NumResources) {
    This->lpVtbl->AcquireWrappedResources(This,ppResources,NumResources);
}
#endif
#endif

#endif


#endif  /* __ID3D11On12Device_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ID3D11On12Device1 interface
 */
#ifndef __ID3D11On12Device1_INTERFACE_DEFINED__
#define __ID3D11On12Device1_INTERFACE_DEFINED__

DEFINE_GUID(IID_ID3D11On12Device1, 0xbdb64df4, 0xea2f, 0x4c70, 0xb8,0x61, 0xaa,0xab,0x12,0x58,0xbb,0x5d);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("bdb64df4-ea2f-4c70-b861-aaab1258bb5d")
ID3D11On12Device1 : public ID3D11On12Device
{
    virtual HRESULT STDMETHODCALLTYPE GetD3D12Device(
        REFIID riid,
        void **ppvDevice) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ID3D11On12Device1, 0xbdb64df4, 0xea2f, 0x4c70, 0xb8,0x61, 0xaa,0xab,0x12,0x58,0xbb,0x5d)
#endif
#else
typedef struct ID3D11On12Device1Vtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ID3D11On12Device1 *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ID3D11On12Device1 *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ID3D11On12Device1 *This);

    /*** ID3D11On12Device methods ***/
    HRESULT (STDMETHODCALLTYPE *CreateWrappedResource)(
        ID3D11On12Device1 *This,
        IUnknown *pResource12,
        const D3D11_RESOURCE_FLAGS *pFlags11,
        D3D12_RESOURCE_STATES InState,
        D3D12_RESOURCE_STATES OutState,
        REFIID riid,
        void **ppResource11);

    void (STDMETHODCALLTYPE *ReleaseWrappedResources)(
        ID3D11On12Device1 *This,
        ID3D11Resource *const *ppResources,
        UINT NumResources);

    void (STDMETHODCALLTYPE *AcquireWrappedResources)(
        ID3D11On12Device1 *This,
        ID3D11Resource *const *ppResources,
        UINT NumResources);

    /*** ID3D11On12Device1 methods ***/
    HRESULT (STDMETHODCALLTYPE *GetD3D12Device)(
        ID3D11On12Device1 *This,
        REFIID riid,
        void **ppvDevice);

    END_INTERFACE
} ID3D11On12Device1Vtbl;

interface ID3D11On12Device1 {
    CONST_VTBL ID3D11On12Device1Vtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ID3D11On12Device1_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ID3D11On12Device1_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ID3D11On12Device1_Release(This) (This)->lpVtbl->Release(This)
/*** ID3D11On12Device methods ***/
#define ID3D11On12Device1_CreateWrappedResource(This,pResource12,pFlags11,InState,OutState,riid,ppResource11) (This)->lpVtbl->CreateWrappedResource(This,pResource12,pFlags11,InState,OutState,riid,ppResource11)
#define ID3D11On12Device1_ReleaseWrappedResources(This,ppResources,NumResources) (This)->lpVtbl->ReleaseWrappedResources(This,ppResources,NumResources)
#define ID3D11On12Device1_AcquireWrappedResources(This,ppResources,NumResources) (This)->lpVtbl->AcquireWrappedResources(This,ppResources,NumResources)
/*** ID3D11On12Device1 methods ***/
#define ID3D11On12Device1_GetD3D12Device(This,riid,ppvDevice) (This)->lpVtbl->GetD3D12Device(This,riid,ppvDevice)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT ID3D11On12Device1_QueryInterface(ID3D11On12Device1* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG ID3D11On12Device1_AddRef(ID3D11On12Device1* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG ID3D11On12Device1_Release(ID3D11On12Device1* This) {
    return This->lpVtbl->Release(This);
}
/*** ID3D11On12Device methods ***/
static FORCEINLINE HRESULT ID3D11On12Device1_CreateWrappedResource(ID3D11On12Device1* This,IUnknown *pResource12,const D3D11_RESOURCE_FLAGS *pFlags11,D3D12_RESOURCE_STATES InState,D3D12_RESOURCE_STATES OutState,REFIID riid,void **ppResource11) {
    return This->lpVtbl->CreateWrappedResource(This,pResource12,pFlags11,InState,OutState,riid,ppResource11);
}
static FORCEINLINE void ID3D11On12Device1_ReleaseWrappedResources(ID3D11On12Device1* This,ID3D11Resource *const *ppResources,UINT NumResources) {
    This->lpVtbl->ReleaseWrappedResources(This,ppResources,NumResources);
}
static FORCEINLINE void ID3D11On12Device1_AcquireWrappedResources(ID3D11On12Device1* This,ID3D11Resource *const *ppResources,UINT NumResources) {
    This->lpVtbl->AcquireWrappedResources(This,ppResources,NumResources);
}
/*** ID3D11On12Device1 methods ***/
static FORCEINLINE HRESULT ID3D11On12Device1_GetD3D12Device(ID3D11On12Device1* This,REFIID riid,void **ppvDevice) {
    return This->lpVtbl->GetD3D12Device(This,riid,ppvDevice);
}
#endif
#endif

#endif


#endif  /* __ID3D11On12Device1_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ID3D11On12Device2 interface
 */
#ifndef __ID3D11On12Device2_INTERFACE_DEFINED__
#define __ID3D11On12Device2_INTERFACE_DEFINED__

DEFINE_GUID(IID_ID3D11On12Device2, 0xdc90f331, 0x4740, 0x43fa, 0x86,0x6e, 0x67,0xf1,0x2c,0xb5,0x82,0x23);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("dc90f331-4740-43fa-866e-67f12cb58223")
ID3D11On12Device2 : public ID3D11On12Device1
{
    virtual HRESULT STDMETHODCALLTYPE UnwrapUnderlyingResource(
        ID3D11Resource *pResource11,
        ID3D12CommandQueue *pCommandQueue,
        REFIID riid,
        void **ppvResource12) = 0;

    virtual HRESULT STDMETHODCALLTYPE ReturnUnderlyingResource(
        ID3D11Resource *pResource11,
        UINT NumSync,
        UINT64 *pSignalValues,
        ID3D12Fence **ppFences) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ID3D11On12Device2, 0xdc90f331, 0x4740, 0x43fa, 0x86,0x6e, 0x67,0xf1,0x2c,0xb5,0x82,0x23)
#endif
#else
typedef struct ID3D11On12Device2Vtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ID3D11On12Device2 *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ID3D11On12Device2 *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ID3D11On12Device2 *This);

    /*** ID3D11On12Device methods ***/
    HRESULT (STDMETHODCALLTYPE *CreateWrappedResource)(
        ID3D11On12Device2 *This,
        IUnknown *pResource12,
        const D3D11_RESOURCE_FLAGS *pFlags11,
        D3D12_RESOURCE_STATES InState,
        D3D12_RESOURCE_STATES OutState,
        REFIID riid,
        void **ppResource11);

    void (STDMETHODCALLTYPE *ReleaseWrappedResources)(
        ID3D11On12Device2 *This,
        ID3D11Resource *const *ppResources,
        UINT NumResources);

    void (STDMETHODCALLTYPE *AcquireWrappedResources)(
        ID3D11On12Device2 *This,
        ID3D11Resource *const *ppResources,
        UINT NumResources);

    /*** ID3D11On12Device1 methods ***/
    HRESULT (STDMETHODCALLTYPE *GetD3D12Device)(
        ID3D11On12Device2 *This,
        REFIID riid,
        void **ppvDevice);

    /*** ID3D11On12Device2 methods ***/
    HRESULT (STDMETHODCALLTYPE *UnwrapUnderlyingResource)(
        ID3D11On12Device2 *This,
        ID3D11Resource *pResource11,
        ID3D12CommandQueue *pCommandQueue,
        REFIID riid,
        void **ppvResource12);

    HRESULT (STDMETHODCALLTYPE *ReturnUnderlyingResource)(
        ID3D11On12Device2 *This,
        ID3D11Resource *pResource11,
        UINT NumSync,
        UINT64 *pSignalValues,
        ID3D12Fence **ppFences);

    END_INTERFACE
} ID3D11On12Device2Vtbl;

interface ID3D11On12Device2 {
    CONST_VTBL ID3D11On12Device2Vtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ID3D11On12Device2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ID3D11On12Device2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ID3D11On12Device2_Release(This) (This)->lpVtbl->Release(This)
/*** ID3D11On12Device methods ***/
#define ID3D11On12Device2_CreateWrappedResource(This,pResource12,pFlags11,InState,OutState,riid,ppResource11) (This)->lpVtbl->CreateWrappedResource(This,pResource12,pFlags11,InState,OutState,riid,ppResource11)
#define ID3D11On12Device2_ReleaseWrappedResources(This,ppResources,NumResources) (This)->lpVtbl->ReleaseWrappedResources(This,ppResources,NumResources)
#define ID3D11On12Device2_AcquireWrappedResources(This,ppResources,NumResources) (This)->lpVtbl->AcquireWrappedResources(This,ppResources,NumResources)
/*** ID3D11On12Device1 methods ***/
#define ID3D11On12Device2_GetD3D12Device(This,riid,ppvDevice) (This)->lpVtbl->GetD3D12Device(This,riid,ppvDevice)
/*** ID3D11On12Device2 methods ***/
#define ID3D11On12Device2_UnwrapUnderlyingResource(This,pResource11,pCommandQueue,riid,ppvResource12) (This)->lpVtbl->UnwrapUnderlyingResource(This,pResource11,pCommandQueue,riid,ppvResource12)
#define ID3D11On12Device2_ReturnUnderlyingResource(This,pResource11,NumSync,pSignalValues,ppFences) (This)->lpVtbl->ReturnUnderlyingResource(This,pResource11,NumSync,pSignalValues,ppFences)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT ID3D11On12Device2_QueryInterface(ID3D11On12Device2* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG ID3D11On12Device2_AddRef(ID3D11On12Device2* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG ID3D11On12Device2_Release(ID3D11On12Device2* This) {
    return This->lpVtbl->Release(This);
}
/*** ID3D11On12Device methods ***/
static FORCEINLINE HRESULT ID3D11On12Device2_CreateWrappedResource(ID3D11On12Device2* This,IUnknown *pResource12,const D3D11_RESOURCE_FLAGS *pFlags11,D3D12_RESOURCE_STATES InState,D3D12_RESOURCE_STATES OutState,REFIID riid,void **ppResource11) {
    return This->lpVtbl->CreateWrappedResource(This,pResource12,pFlags11,InState,OutState,riid,ppResource11);
}
static FORCEINLINE void ID3D11On12Device2_ReleaseWrappedResources(ID3D11On12Device2* This,ID3D11Resource *const *ppResources,UINT NumResources) {
    This->lpVtbl->ReleaseWrappedResources(This,ppResources,NumResources);
}
static FORCEINLINE void ID3D11On12Device2_AcquireWrappedResources(ID3D11On12Device2* This,ID3D11Resource *const *ppResources,UINT NumResources) {
    This->lpVtbl->AcquireWrappedResources(This,ppResources,NumResources);
}
/*** ID3D11On12Device1 methods ***/
static FORCEINLINE HRESULT ID3D11On12Device2_GetD3D12Device(ID3D11On12Device2* This,REFIID riid,void **ppvDevice) {
    return This->lpVtbl->GetD3D12Device(This,riid,ppvDevice);
}
/*** ID3D11On12Device2 methods ***/
static FORCEINLINE HRESULT ID3D11On12Device2_UnwrapUnderlyingResource(ID3D11On12Device2* This,ID3D11Resource *pResource11,ID3D12CommandQueue *pCommandQueue,REFIID riid,void **ppvResource12) {
    return This->lpVtbl->UnwrapUnderlyingResource(This,pResource11,pCommandQueue,riid,ppvResource12);
}
static FORCEINLINE HRESULT ID3D11On12Device2_ReturnUnderlyingResource(ID3D11On12Device2* This,ID3D11Resource *pResource11,UINT NumSync,UINT64 *pSignalValues,ID3D12Fence **ppFences) {
    return This->lpVtbl->ReturnUnderlyingResource(This,pResource11,NumSync,pSignalValues,ppFences);
}
#endif
#endif

#endif


#endif  /* __ID3D11On12Device2_INTERFACE_DEFINED__ */

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES) */
DEFINE_GUID(IID_ID3D11On12Device,0x85611e73,0x70a9,0x490e,0x96,0x14,0xa9,0xe3,0x02,0x77,0x79,0x04);
DEFINE_GUID(IID_ID3D11On12Device1,0xbdb64df4,0xea2f,0x4c70,0xb8,0x61,0xaa,0xab,0x12,0x58,0xbb,0x5d);
DEFINE_GUID(IID_ID3D11On12Device2,0xdc90f331,0x4740,0x43fa,0x86,0x6e,0x67,0xf1,0x2c,0xb5,0x82,0x23);
/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __d3d11on12_h__ */