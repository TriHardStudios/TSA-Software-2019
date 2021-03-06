#ifndef PLEXI_RENDERER_HPP
#define PLEXI_RENDERER_HPP

#include <iostream>
#include <thread>
#include <ths/log.hpp>



namespace Plexi {

#ifndef PLEXI_LIBRARY_ACTIVE


    const PLEXI_GFX_BACKENDS PLEXI_DEFAULT_GFX_BACKEND = PLEXI_OPENGL;
    //Where the config will be stored
    static PlexiConfig activeConfig;
//    std::thread plexiLoopThread;
    static std::vector<Plexi::Shaders::ShaderCreateInfo> loadedShaders;
    static std::vector<Plexi::Buffer::BufferCreateInfo> bufferData;

    static std::vector<RenderTask> renderQueue;

#endif //PLEXI_LIBRARY_ACTIVE

    //will init Plexi to default settings
    void initPlexi();

    //will init Plexi to user provided settings
    void initPlexi(PlexiConfig&);

//    void runPlexi();



    void submitScene(const std::vector<StandardRenderTask>& tasks);

    void submitScene(const std::vector<TextRenderTask>& tasks);

    void enableTextCaching(bool newStatus);

    void cacheTextNow();

    void removeTexture (uint32_t textureId);

    void removeTexture();

    void removeFont(uint32_t fontId);

    void removeFont();


    void setClearColor(const float &r, const float &g, const float &b, const float &a);

    void onUpdate();

    void cleanupPlexi();

    PLEXI_GFX_BACKENDS getActiveBackend();

    //Adds a render task to the active backend. Returns false if it fails



}


#endif//PLEXI_RENDERER_HPP