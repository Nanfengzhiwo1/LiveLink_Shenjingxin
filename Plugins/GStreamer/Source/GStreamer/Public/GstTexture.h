#pragma once

#include "GstSampleImpl.h"
#include "Engine/Texture2D.h"
#include "GstVideoFormat.h"
#include "ITextureUpdateListener.h"

class IGstTextureCallback
{
protected:
	~IGstTextureCallback() = default;
public:
	virtual void CbGstTextureCreated() = 0;
};

class FGstTexture
{
public:

	FGstTexture(FString Name, class IGstAppSink* AppSink, IGstTextureCallback* Callback);
	virtual ~FGstTexture();
	virtual void Destroy();

	void SubmitSample(class IGstSample* Sample);
	void TickGameThread();
	void Release();

	inline UTexture2D* GetTextureObject() { return m_TextureObject; }
	inline EGstVideoFormat GetGstFormat() const { return m_GstFormat; }
	inline EPixelFormat GetUeFormat() const { return m_UeFormat; }
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	inline void SetListener(ITextureUpdateListener* Listener) { UpdateListener = Listener; }
private:
	
	class IGstSample* SwapSample(class IGstSample* NewSample);
	void ReleaseSample(class IGstSample* Sample);
	bool Resize(class IGstSample* Sample);

	void CreateTexture();
	void RenderCmd_UpdateTexture(class IGstSample* Sample);
	void UpdateTextureOnRenderThread(IGstSample* Sample);

private:
	ITextureUpdateListener* UpdateListener = nullptr;
	FString m_Name;
	class IGstAppSink* m_AppSink = nullptr;
	IGstTextureCallback* m_Callback = nullptr;
	UTexture2D* m_TextureObject = nullptr;

	class IGstSample* m_Sample = nullptr;
	FCriticalSection m_SampleMx;

	EGstVideoFormat m_GstFormat = EGstVideoFormat::GST_VIDEO_FORMAT_UNKNOWN;
	EPixelFormat m_UeFormat = EPixelFormat::PF_Unknown;
	TextureCompressionSettings m_Compression = TextureCompressionSettings::TC_VectorDisplacementmap;
	int m_Width = 0;
	int m_Height = 0;
	int m_Pitch = 0;

	double m_StatTimer = 0;
	int m_SampleCount = 0;
	int m_TickCount = 0;
	int m_EnqueCount = 0;
	int m_RenderCount = 0;
};
