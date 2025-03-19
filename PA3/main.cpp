#include "avl_map.h"
#include "avl_node.h"
#include "data.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include<sstream>
#include<string>
#include<map>
#include<list>
#include<ctime>
#include <vector>

using std::ifstream;
using std::endl;
using std::stringstream;
using std::string;
using std::cout;
using std::getline;
using std::stoi;
using std::map;
using std::vector;
using std::list;

int main(void)
{
    ifstream infile("uszips.csv");
    AVL_Map<int, USCity> AVLMap;
    map<int, USCity> stdMap;
    list<int> keyList;
    string line;


    getline(infile, line);
    while(getline(infile, line))
    {
        USCity dataPoint;
        Node<int, USCity>* node = new Node<int, USCity>(0, dataPoint);
        stringstream substr(line);
        
        
        string key;
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

        getline(substr, key, ',');
        getline(substr, lat, ',');
        dataPoint.setLat(lat);
        getline(substr, lng, ',');
        dataPoint.setLng(lng);
        getline(substr, city, ',');
        dataPoint.setCity(city);
        getline(substr, state_id, ',');
        dataPoint.setStateId(state_id);
        getline(substr, state_name, ',');
        dataPoint.setStateName(state_name);
        getline(substr, zcta, ',');
        dataPoint.setZcta(zcta);
        getline(substr, population, ',');
        dataPoint.setPopulation(population);
        getline(substr, density, ',');
        dataPoint.setDensity(density);
        getline(substr, county_fips, ',');
        dataPoint.setCountyFips(county_fips);
        getline(substr, county_name, ',');
        dataPoint.setCountyName(county_name);
        getline(substr, county_weights, ',');
        if(county_weights.front() == '"'){
            string extraToken;
            while(county_weights.back() != '"'){
                getline(substr, extraToken, ',');
                county_weights += "," + extraToken;
            }
        }
        dataPoint.setCountyWeights(county_weights);
        getline(substr, county_names_all, ',');
        dataPoint.setCountyNamesAll(county_names_all);
        getline(substr, county_fips_all, ',');
        dataPoint.setCountyFipsAll(county_fips_all);
        getline(substr, imprecise, ',');
        dataPoint.setImprecise(imprecise);
        getline(substr, military, ',');
        dataPoint.setMilitary(military);
        getline(substr, timezone, ',');
        dataPoint.setTimezone(timezone);

        node->setKey(stoi(key));
        node->setValue(dataPoint);
        AVLMap.insert(stoi(key), dataPoint);
        stdMap.insert({stoi(key), dataPoint});
        keyList.push_back(stoi(key));

        // AVLMap.printNode(node);
        // AVLMap.printTree(AVLMap.getRoot());
    }
    infile.close();

    vector<int> selectedKeys;
    vector<int> totalKeys(keyList.begin(), keyList.end());
    int sampleSize = 1000;

    srand(time(0));
    for(int i = 0; i < sampleSize; ++i)
    {
        int randomNumber = rand() % totalKeys.size();
        selectedKeys.push_back(totalKeys[randomNumber]);
    }


    //used geeksforgeeks and stack overflow to assist in building clocks
    clock_t startAVL = clock();
    for (int index : selectedKeys) {
        auto it = AVLMap.find(index);
    }
    clock_t endAVL = clock();
    double timeAVL = double(endAVL - startAVL) / CLOCKS_PER_SEC;
    
    clock_t startStd = clock();
    for (int index : selectedKeys) {
        auto it = stdMap.find(index);
    }
    clock_t endStd = clock();
    double timeStd = double(endStd - startStd) / CLOCKS_PER_SEC;
    
    cout << "AVL_Map lookup time: " << timeAVL << " seconds" << endl;
    cout << "std::map lookup time: " << timeStd << " seconds" << endl;


    return 0;
}