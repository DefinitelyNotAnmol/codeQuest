#ifndef MAPPING_H
#define MAPPING_H

#include <utility>
#include <fstream>
#include <array>

namespace cdqst {
    std::array<std::pair<float, float>, 4> locations;
    bool initialize_locations();

    class Mapping {
        float m_latitude;
        float m_longitude;
    public:
        Mapping() {
            
        }

        Mapping(int index) {
            m_latitude = locations[index].first;
            m_longitude = locations[index].second;
        }

        void setLat(float lat);
        void setLong(float longi);
        float latitude() const;
        float longitude() const;

        std::pair<float, float> location() const;
    };
}

bool cdqst::initialize_locations() {
    locations[0] = std::make_pair(28.721069f, 77.141434f); //building
    locations[1] = std::make_pair(28.720390f, 77.141624f); //goal
    locations[2] = std::make_pair(28.721128f, 77.142025f); //lawn
    locations[3] = std::make_pair(28.720843f, 77.140905f); //canteen
    return true;
}

void cdqst::Mapping::setLat(float lat) {
    this->m_latitude = lat;
}

void cdqst::Mapping::setLong(float longi) {
    this->m_longitude = longi;
}

float cdqst::Mapping::latitude() const {
    return this->m_latitude;
}

float cdqst::Mapping::longitude() const {
    return this->m_longitude;
}

std::pair<float, float> cdqst::Mapping::location() const {
    return std::make_pair(this->m_latitude, this->m_longitude);
}

#endif