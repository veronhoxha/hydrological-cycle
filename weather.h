#ifndef WEATHER_H_INCLUDED
#define WEATHER_H_INCLUDED

#pragma once
#include <string>

class Plain;
class Grassland;
class LakesRegion;

class Weather{
protected:
    int humidity;
    Weather(int &h): humidity(h) {}
public:
    virtual Weather* change(Plain *p) = 0;
    virtual Weather* change(Grassland *p) = 0;
    virtual Weather* change(LakesRegion *p) = 0;
    virtual ~Weather() {}
    int getHumidity (){return humidity;}
};


class Sunny : public Weather
{
public:
    static Sunny* instance(int &h);
    Weather* change(Plain *p) override;
    Weather* change(Grassland *p) override;
    Weather* change(LakesRegion *p) override;
    static void destroy() ;
protected:
    Sunny(int &h) : Weather(h){}
private:
    static Sunny* _instance;
};


class Cloudy : public Weather
{
public:
    static Cloudy* instance(int &h);
    Weather* change(Plain *p) override;
    Weather* change(Grassland *p) override;
    Weather* change(LakesRegion *p) override;
    static void destroy() ;
protected:
    Cloudy(int &h) : Weather(h){}
private:
    static Cloudy* _instance;
};


class Rainy : public Weather
{
public:
    static Rainy* instance(int &h);
    Weather* change(Plain *p) override;
    Weather* change(Grassland *p) override;
    Weather* change(LakesRegion   *p) override;
    static void destroy() ;
protected:
    Rainy(int &h) : Weather(h){}
private:
    static Rainy* _instance;
};


#endif // WEATHER_H_INCLUDED
