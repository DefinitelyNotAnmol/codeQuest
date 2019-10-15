#include <iostream>
#include <map>
#include <string>
#include <iomanip>

#include "mapping.h"

#define DEBUG 0

#ifdef DEBUG 
    #include <chrono>

    class Timing {
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::chrono::time_point<std::chrono::high_resolution_clock> end;
        std::chrono::duration<float> duration;
    public:
        Timing() {
            start = std::chrono::high_resolution_clock::now();
        }

        ~Timing() {
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << duration.count() << std::endl;
        }
    };

    #define print(x) std::cout << x << std::endl;
#else
    #define print(x) 
#endif

int main(int argc, char const *argv[]) {
    #if DEBUG
        Timing T;
    #endif

    cdqst::initialize_locations();
    std::map<std::string, cdqst::Mapping> map;
    map["CDQST"] = cdqst::Mapping(0); // Location leads to Stairs
    map["STAIRS"] = cdqst::Mapping(1); // 
    map["GOAL"] = cdqst::Mapping(2);
    map["LAWN"] = cdqst::Mapping(3);

    std::string key;

    std::cout << "Enter the key phrase: ";
    std::cin >> key;

    if (map.find(key) != map.end()) {
        auto location = map[key].location();
        std::cout << std::fixed << std::setprecision(6) << "(" << location.first << ", " << location.second << ")" << std::endl;
    } else {
        std::cout << "wrong key" << std::endl;
    }

    return 0;
}
//buildings - 27.721048, 77.141363
//goal post - 28.720397, 77.141560
//front lawn - 28.721152, 77.141973
//canteen - 28.720870, 77.140926