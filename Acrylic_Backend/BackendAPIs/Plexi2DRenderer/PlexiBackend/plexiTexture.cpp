#include "plexiShaders.hpp"
#include "plexiBuffer.hpp"
#include "plexiHelper.hpp"
#include "acrylic_plexiBackend.hpp"
#include "./../plexi_usrStructs.hpp"

#include "plexiTexture.hpp"


void Plexi::Texture::create2DTexture(Plexi::TextureCreateInfo &createInfo, const Plexi::PLEXI_GFX_BACKENDS &backendToUse) {
    if(!GFXBackendMap[backendToUse]) {
        std::cerr << "Texture Creation Failed: Invalid Backend" << std::endl;
        return;
    }

    Plexi2DTexture* newTexture = GFXBackendMap[backendToUse]->getNewTexture();

    newTexture->createTexture(createInfo.textureData, createInfo.dataSize, createInfo.height, createInfo.width, createInfo.channelCount);

    GFXBackendMap[backendToUse]->addTexture(newTexture);
    newTexture->bind(0);
}