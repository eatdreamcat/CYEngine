#pragma once
#include "CObject.h"
#include "Material.h"
class Pass :
    public CObject
{
    
public:
    enum class PassEvent
    {
        BeforeRendering = 0,
        BeforeRenderingShadows = 50,
        AfterRenderingShadows = 100,
        BeforeRenderingPrePasses = 150,
        AfterRenderingPrePasses = 200,
        BeforeRenderingGbuffer = 210,
        AfterRenderingGbuffer = 220,
        BeforeRenderingDeferredLights = 230,
        AfterRenderingDeferredLights = 240,
        BeforeRenderingOpaques = 250,
        AfterRenderingOpaques = 300,
        BeforeRenderingSkybox = 350,
        AfterRenderingSkybox = 400,
        BeforeRenderingTransparents = 450,
        AfterRenderingTransparents = 500,
        BeforeRenderingPostProcessing = 550,
        AfterRenderingPostProcessing = 600,
        AfterRendering = 1000


    };
    virtual ~Pass() {}
    PassEvent m_passEvent = PassEvent::BeforeRenderingOpaques;
    bool operator > (const Pass& pass) {
        return m_passEvent > pass.m_passEvent;
    }

    bool operator == (const Pass& pass) {
        return m_passEvent == pass.m_passEvent;
    }

    bool operator < (const Pass& pass) {
        return m_passEvent < pass.m_passEvent;
    }
    virtual void Setup();

    virtual void Excute();

private:
    Material& m_material;

};

