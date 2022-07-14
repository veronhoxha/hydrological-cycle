#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "area.h"
#include "weather.h"
#include "weather.cpp"

using namespace std;

bool checkAllSameType(vector<Area*> &areas) {
    string type = areas[0]->getType();
    for (int i = 1; i<areas.size(); i++)
    {
        if(areas[i]->getType().compare(type) != 0) {
            return false;
        }
    }
    return true;
}

void print(vector<Area*> &areas, Weather* weather) {

    for (int i = 0; i < areas.size(); i++)
        cout << "Area owner: " << areas[i]->getName() << ", Area type: " << areas[i]->getType() << ", Amount of water: " << areas[i]->getWater() << endl;
        cout << "Air humidity: " << weather->getHumidity() << endl << endl;
}

void simulate(vector<Area*> &areas, Weather* &weather)
{
    int index = 0;
    while(!checkAllSameType(areas)) {

        print(areas, weather);
        areas[index]->change(weather);

        string type = areas[index]->getType();
        if(areas[index]->getType().compare("P") == 0) {
            if (areas[index]->getWater() < 0)
            {
                areas[index] = new Plain(areas[index]->getName(), "P", 0);
            }
           else if (areas[index]->getWater() > 15) {
                areas[index] = new Grassland(areas[index]->getName(), "G", areas[index]->getWater());
            }
        }
        else if(areas[index]->getType().compare("G") == 0) {
            if (areas[index]->getWater() < 0)
            {
                areas[index] = new Grassland(areas[index]->getName(), "G", 0);
            }
           else if (areas[index]->getWater() < 16) {
                areas[index] = new Plain(areas[index]->getName(), "P", areas[index]->getWater());
            } else if (areas[index]->getWater() > 50) {
                areas[index] = new LakesRegion(areas[index]->getName(), "L", areas[index]->getWater());
            }
        }
        else if(areas[index]->getType().compare("L") == 0) {
             if (areas[index]->getWater() < 0)
            {
                areas[index] = new LakesRegion(areas[index]->getName(), "L", 0);
            }
            else if (areas[index]->getWater() > 51) {
                areas[index] = new Grassland(areas[index]->getName(), "G", areas[index]->getWater());
            }
        }

        index++;
        if (index == areas.size()) {
            index = 0;
        }
    }
        print(areas, weather);

    //cout << "Simulation is done. All areas have the same type" << endl;
}

void create(const string &str, vector<Area*> &areas, Weather* &weather)
{
    ifstream f(str);
    if(f.fail()) { cout << "Wrong file name!\n"; exit(1);}

    try
    {
    int n; f >> n;
    areas.resize(n);
    for( int i=0; i<n; ++i ){
        char ch; string name; int w;
        f >> name >> ch >> w;
        switch(ch){
            case 'P' : areas[i] = new Plain(name, "P", w); break;
            case 'G' : areas[i] = new Grassland(name, "G", w); break;
            case 'L' : areas[i] = new LakesRegion(name, "L", w); break;
        }
    }
}   catch (exception e) {
        cout << e.what () << endl;
    }

    int humidity;
    f >> humidity;

    if(humidity>70) {
        humidity = 30;
        weather = Rainy::instance(humidity);
    }
    else if (40<=humidity && humidity<=70) {
        if ((humidity-30)*3.3 >= 100) {
            weather = Rainy::instance(humidity);
        } else
        weather = Cloudy::instance(humidity);
    }
    else {
        weather = Sunny::instance(humidity);
    }
}

void destroy(vector<Area*> &areas)
{
    for(int i=0; i<(int)areas.size(); ++i) delete areas[i];
}

void destroyWeather(Weather* &weather)
{
  delete weather;
}

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    vector<Area*> areas;
    Weather* weather;
    create("input.txt", areas, weather);

    simulate(areas, weather);

    destroy(areas);
    destroyWeather(weather);
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("1", "input1*.txt")
{
    vector<Area*> areas;
    Weather* weather;

    create("input11.txt", areas, weather);
    CHECK(areas.size() == 2);
    destroy(areas);

    create("input12.txt", areas, weather);
    CHECK(areas.size() == 3);
    destroy(areas);

    create("input13.txt", areas, weather);
    CHECK(areas.size() == 5);
    destroy(areas);

    create("input14.txt", areas, weather);
    CHECK(areas.size() == 0);
    destroy(areas);

    destroyWeather(weather);
}

TEST_CASE("2", "input2*.txt")
{
    vector<Area*> areas;
    Weather* weather;

    areas.clear();
    create("input21.txt", areas, weather);
    simulate(areas, weather);

    CHECK(areas[0]->getName() == "King");
    CHECK(areas[1]->getName() == "Queen");
    CHECK(areas[2]->getWater() == 25);
    CHECK(areas[2]->getType() == "G");
    CHECK(weather->getHumidity() == 80);
    destroy(areas);

    create("input22.txt", areas, weather);
    simulate(areas, weather);
    CHECK(areas.size() == 0);
    destroyWeather(weather);
}

TEST_CASE("3", "input3.txt")
{
    vector<Area*> areas;
    Weather* weather;

    areas.clear();
    create("input3.txt", areas, weather);
    simulate(areas, weather);

    CHECK(areas[0]->getName() == "AAA");
    CHECK(areas[1]->getName() == "BBB");
    CHECK(areas[2]->getName() == "CCC");
    CHECK(areas[3]->getName() == "DDD");
    CHECK(areas[0]->getWater() == 65);
    CHECK(areas[1]->getWater() == 68);
    CHECK(areas[2]->getWater() == 79);
    CHECK(areas[3]->getWater() == 22);
    CHECK(areas[0]->getType() == "G");
    CHECK(areas[1]->getType() == "G");
    CHECK(areas[2]->getType() == "G");
    CHECK(areas[3]->getType() == "G");
    CHECK(weather->getHumidity() == 45);
    destroy(areas);

    destroyWeather(weather);
}


TEST_CASE("4", "input4.txt")
{
    vector<Area*> areas;
    Weather* weather;

    areas.clear();
    create("input4.txt", areas, weather);
    simulate(areas, weather);

    CHECK(areas[0]->getName() == "Loko");
    CHECK(areas[1]->getName() == "Oso");
    CHECK(areas[2]->getName() == "Imo");
    CHECK(areas[0]->getWater() == 56);
    CHECK(areas[1]->getWater() == 38);
    CHECK(areas[2]->getWater() == 56);
    CHECK(areas[0]->getType() == "G");
    CHECK(areas[1]->getType() == "G");
    CHECK(areas[2]->getType() == "G");
    CHECK(weather->getHumidity() == 85);
    destroy(areas);

    destroyWeather(weather);
}

TEST_CASE("5", "")
{
    vector<Area*> areas;
    Weather* weather;

    areas.clear();
    areas.push_back(new Plain("Mike","P", 23));

    CHECK(areas[0]->getName() == "Mike");
    CHECK(areas[0]->getType() == "P");
    CHECK(areas[0]->getWater() == 23);

    areas.push_back(new Grassland("Elon","G", 109));
    CHECK(areas[1]->getName() == "Elon");
    CHECK(areas[1]->getType() == "G");
    CHECK(areas[1]->getWater() == 109);

    areas.push_back(new LakesRegion("Jon","L", 11));
    CHECK(areas[2]->getName() == "Jon");
    CHECK(areas[2]->getType() == "L");
    CHECK(areas[2]->getWater() == 11);
}

#endif
