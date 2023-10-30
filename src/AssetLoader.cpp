#include "AssetLoader.h"

namespace PastequeArena {
    AssetLoader::AssetLoader() {
#if defined(PLATFORM_DESKTOP)
#if PA_PACKAGED
        assetRootPath = {GetApplicationDirectory()};
#else
        assetRootPath = std::filesystem::path{PA_DEV_ASSETS_DIR};
#endif
        if (!exists(assetRootPath)) {
            TraceLog(LOG_FATAL, "Asset root path does not exist: %s", assetRootPath.string().c_str());
        }
#elif defined(PLATFORM_ANDROID)
        assetRootPath = std::filesystem::path{};
#endif
    }

    raylib::Image AssetLoader::LoadImage(const char *path) {
        return raylib::Image{(assetRootPath / std::filesystem::path{path}).string()};
    }

    raylib::Texture AssetLoader::LoadTexture(const char *path) {
        return raylib::Texture{(assetRootPath / std::filesystem::path{path}).string()};
    }
} // PastequeArena