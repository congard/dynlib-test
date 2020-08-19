#include <iostream>

#include "Animal.h"

#include "tulz/DynamicLibrary.h"

using namespace tulz;
using namespace std;

#define function(name) name (*)

void test(const string &file) {
    DynamicLibrary dl(file);
    auto create = dl.getAddress<function(Animal*)()>("create_object");
    auto destroy = dl.getAddress<function(void)(Animal*)>("destroy_object");

    auto animal = create();
    animal->voice();
    destroy(animal);
}

int main() {
    cout << "Type library name to load\n"
            "For example: dog.dll (MSVC Windows); libcat.so (Linux)\n";

    while (true) {
        string cmd;

        cout << "\n> ";
        cin >> cmd;

        if (cmd == "exit")
            break;

        cout << "=== Loading " << cmd << " ===\n";
        DynamicLibrary dl(cmd);

        {
            auto error = DynamicLibrary::getError();

            if (error.error) {
                cout << error.message << "\n";
                cout << "=== Failed to load " << cmd << " ===\n";
                continue;
            }
        }

        auto create = dl.getAddress<function(Animal*)()>("create_object");
        auto destroy = dl.getAddress<function(void)(Animal*)>("destroy_object");

        auto animal = create();
        animal->voice();
        destroy(animal);

        cout << "=== Closing " << cmd << " ===\n";
    }

    return 0;
}
