#include "acrylic_plexiRenderer_core.hpp"

#include <GLFW/glfw3.h>

int main(){ 
    initLogger("Plexi2D", log_severity_information, log_mode_all)
    Plexi::initPlexi();
    Plexi::TextureCreateInfo textureCreateInfo = {};
    textureCreateInfo.height = 1;
    textureCreateInfo.width = 1;
    textureCreateInfo.channelCount = 4;
    textureCreateInfo.dataSize = sizeof(uint32_t);
    uint32_t data = 0xFFFFFFFF;
    textureCreateInfo.textureData.dataType.generic = &data;
    textureCreateInfo.textureData.usingGenericType = true;



    uint32_t plainWhiteTexture = Plexi::Texture::create2DTexture(textureCreateInfo, Plexi::getActiveBackend());
    while(!glfwWindowShouldClose(Plexi::getWindowRef())){
        glfwPollEvents();
        Plexi::onUpdate();
    }


//    std::cin.get();
    Plexi::cleanupPlexi();

    endLogger()



    return 0;
}