#ifndef DYNLIB_TEST_DYNAMICLIBRARY_H
#define DYNLIB_TEST_DYNAMICLIBRARY_H

#include <string>

namespace tulz {
class DynamicLibrary {
public:
    struct Error {
        bool error;
        std::string message;
    };

public:
    DynamicLibrary();
    explicit DynamicLibrary(const std::string &path);
    ~DynamicLibrary();

    void load(const std::string &path);
    void close();

    bool isLoaded() const;

    void* getAddress(const std::string &name);

    template<typename T>
    T getAddress(const std::string &name) {
        return reinterpret_cast<T>(getAddress(name));
    }

    static Error getError();

private:
    void *lib = nullptr;
};
}

#endif //DYNLIB_TEST_DYNAMICLIBRARY_H
