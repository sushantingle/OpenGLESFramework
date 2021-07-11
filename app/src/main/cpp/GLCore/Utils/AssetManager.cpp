//
// Created by Sushant on 11-07-2021.
//
#include "AssetManager.h"
#include "../GLCore.h"

namespace GLCore::Utils {
    AssetManager AssetManager::m_Instance;

    const char* AssetManager::ReadFile(const char* filepath) {
        AAsset* asset = AAssetManager_open(m_AAssetManager, filepath, AASSET_MODE_UNKNOWN);
        if (asset == nullptr)
        {
            LOGE("Could not load asset %s", filepath);
            return nullptr;
        }
        const void* buffer = AAsset_getBuffer(asset);
        if (buffer == nullptr)
        {
            LOGE("Failed to read buffer of asset %s", filepath);
            return nullptr;
        }

        return static_cast<const char*>(buffer);
    }
}
