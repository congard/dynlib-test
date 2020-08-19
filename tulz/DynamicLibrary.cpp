#include "DynamicLibrary.h"

#ifndef WIN32
#include <dlfcn.h>
#else
#include <windows.h>
#endif

using namespace std;

namespace tulz {
DynamicLibrary::DynamicLibrary() = default;

DynamicLibrary::DynamicLibrary(const string &path) {
    load(path);
}

DynamicLibrary::~DynamicLibrary() {
    close();
}

void DynamicLibrary::load(const string &path) {
    if (isLoaded())
        close();

#ifndef WIN32
    lib = dlopen(path.c_str(), RTLD_LAZY);
#else
    SetLastError(0);
    lib = LoadLibrary(path.c_str());
#endif
}

void DynamicLibrary::close() {
    if (isLoaded()) {
#ifndef WIN32
        dlclose(lib);
#else
        FreeLibrary(reinterpret_cast<HINSTANCE>(lib));
#endif
    }

    lib = nullptr;
}

bool DynamicLibrary::isLoaded() const {
    return lib != nullptr;
}

void* DynamicLibrary::getAddress(const std::string &name) {
#ifndef WIN32
    return dlsym(lib, name.c_str());
#else
    return reinterpret_cast<void*>(GetProcAddress(reinterpret_cast<HINSTANCE>(lib), name.c_str()));
#endif
}

DynamicLibrary::Error DynamicLibrary::getError() {
    Error error;
    error.error = false;

#ifndef WIN32
    auto dlError = dlerror();

    if (dlError != nullptr) {
        error.error = true;
        error.message = dlError;
    }
#else
    auto lastError = GetLastError();

    if (lastError != 0) {
        error.error = true;
        error.message = to_string(lastError);
    }

    SetLastError(0);
#endif

    return error;
}
}
