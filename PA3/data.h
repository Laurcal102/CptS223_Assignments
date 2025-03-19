#pragma once

#include <ostream>
#include <string>
#include <iostream>

using std::ostream;
using std::string;

class USCity
{
    public:

    USCity() : lat(""), lng(""), city(""), state_id(""), state_name(""), 
                 zcta(""), population(""), density(""), county_fips(""), county_name(""), 
                 county_weights(""), county_names_all(""), county_fips_all(""), imprecise(""), 
                 military(""), timezone("") {};
    
    // Setters
    void setLat(const std::string& value) { lat = value; }
    void setLng(const std::string& value) { lng = value; }
    void setCity(const std::string& value) { city = value; }
    void setStateId(const std::string& value) { state_id = value; }
    void setStateName(const std::string& value) { state_name = value; }
    void setZcta(const std::string& value) { zcta = value; }
    void setPopulation(const std::string& value) { population = value; }
    void setDensity(const std::string& value) { density = value; }
    void setCountyFips(const std::string& value) { county_fips = value; }
    void setCountyName(const std::string& value) { county_name = value; }
    void setCountyWeights(const std::string& value) { county_weights = value; }
    void setCountyNamesAll(const std::string& value) { county_names_all = value; }
    void setCountyFipsAll(const std::string& value) { county_fips_all = value; }
    void setImprecise(const std::string& value) { imprecise = value; }
    void setMilitary(const std::string& value) { military = value; }
    void setTimezone(const std::string& value) { timezone = value; }

    USCity& operator=(const USCity& other) {
        if (this != &other) {
            lat = other.lat;
            lng = other.lng;
            city = other.city;
            state_id = other.state_id;
            state_name = other.state_name;
            zcta = other.zcta;
            population = other.population;
            density = other.density;
            county_fips = other.county_fips;
            county_name = other.county_name;
            county_weights = other.county_weights;
            county_names_all = other.county_names_all;
            county_fips_all = other.county_fips_all;
            imprecise = other.imprecise;
            military = other.military;
            timezone = other.timezone;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& output, USCity city) {
        output << "City: " << city.city << ", State: " << city.state_name 
           << " (" << city.state_id << ")\n"
           << "Latitude: " << city.lat << ", Longitude: " << city.lng << "\n"
           << "Population: " << city.population << ", Density: " << city.density << "\n"
           << "County: " << city.county_name << " (FIPS: " << city.county_fips << ")\n"
           << "Timezone: " << city.timezone;
        return output;
    }

    private:
    string lat;
    string lng;
    string city;
    string state_id;
    string state_name;
    string zcta;
    string population;
    string density;
    string county_fips;
    string county_name;
    string county_weights;
    string county_names_all;
    string county_fips_all;
    string imprecise;
    string military;
    string timezone;
};



