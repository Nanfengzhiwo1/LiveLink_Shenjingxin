// Copyright (c) 2022 Anders Xiao. All rights reserved.
// https://github.com/endink
#ifndef COMMONS_H
#define COMMONS_H

#include <cstdint>

#if defined(_MSC_VER) // M$VS
#define DLL_EXPORT __declspec(dllexport)
#define DLL_IMPORT __declspec(dllimport)
#elif defined(__GNUC__) // GCC
#define DLL_EXPORT __attribute__((visibility("default")))
#define DLL_IMPORT
#else
#define DLL_EXPORT
#define DLL_IMPORT
#pragma warning Unknown dynamic link import/export semantics.
#endif

#if defined(MP_EXPORTS)
#define MP_API DLL_EXPORT
#elif defined(MP_IMPORTS)
#define MP_API DLL_IMPORT
#else
#define MP_API
#endif

struct StandardString
{
    const char* CString;
    int Length;
};

struct SerializedProto {
    const char* str;
    int length;
};

struct SerializedProtoArray {
    SerializedProto* data;
    int size;
};

enum class MediaPipeImageFormat : int {
    UNKNOWN = 0,
    SRGB = 1,
    SRGBA = 2,
    GRAY8 = 3,
    GRAY16 = 4,
    YCBCR420P = 5,
    YCBCR420P10 = 6,
    SRGB48 = 7,
    SRGBA64 = 8,
    VEC32F1 = 9,
    VEC32F2 = 12,
    LAB8 = 10,
    SBGRA = 11
  };

enum class CallbackDataTransport
{
    Reader,
    Protobuf,
};

enum class MediaPipeGraphCnfType
{
    BuiltIn,
    Text,
    File,
};

enum class AnnotationOverlays
{
    HolisticTracking,
    PoseTracking,
    FaceTracking
};

struct BuiltInGraphProperties
{
    AnnotationOverlays Overlay;
    bool RefineFaceLandmarksEnabled;
    bool FaceBlendShapesEnabled;
};

struct MediaPipeGraphCnf
{
    MediaPipeGraphCnfType ContentType;
    const char* GraphConfigContent;
    int GraphConfigContentLen = 0;
    BuiltInGraphProperties BuiltInGraphProps;
};

class IReleasable
{
public:
    virtual ~IReleasable() = default;
    virtual void Release() = 0;
};

class IMediaPipeTexture : public IReleasable
{
public:
    //get uint8*
    virtual void* GetData() const = 0;
    virtual long DataSize() const = 0;
};

class IMediaPipeOutFrame : public IMediaPipeTexture
{
public:
    //get uint8*
    virtual int GetWidth() const = 0;
    virtual int GetHeight() const = 0;
    virtual MediaPipeImageFormat GetFormat() = 0;
};


class IImageSource
{
public:
    virtual ~IImageSource() = default;
    virtual  bool GetTexture(IMediaPipeTexture*& out_texture) = 0;
    virtual bool IsStatic() const = 0;
    virtual int GetWidth() const = 0;
    virtual int GetHeight() const = 0;
    virtual int GetWidthStep() const = 0;
    virtual MediaPipeImageFormat GetFormat() const = 0;
};

#endif // !
