//
// Created by Sushant on 11-07-2021.
//

#ifndef OPENGLESFRAMEWORK_ASSETMANAGER_H
#define OPENGLESFRAMEWORK_ASSETMANAGER_H
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

namespace GLCore::Utils {
    class AssetManager{
    public:
        static AssetManager& GetInstance() {
            return m_Instance;
        }

        void Init(AAssetManager* assetManager) {m_AAssetManager = assetManager;}
        const char* ReadFile(const char* filepath);
    private:
        AAssetManager * m_AAssetManager = nullptr;
        static AssetManager m_Instance;
    };
}

#endif //OPENGLESFRAMEWORK_ASSETMANAGER_H
