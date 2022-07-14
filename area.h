#ifndef AREA_H_INCLUDED
#define AREA_H_INCLUDED

#pragma once
#include <string>
#include "weather.h"

using namespace std;

class Area{
protected:
    string _name;
    int _water;
    string _type;
    Area (const string &str, const string &t, int w = 0) : _name(str), _type(t) ,_water (w) {}
public:
   // string name() const { return _name; }
   // string type () {return _type;}
   // int water () {return _water;}
    void changeWater(int e) {_water += e;}
    virtual void change(Weather* &weather) = 0;
    virtual ~Area () {}
    string getName () {return _name;}
    string getType () {return _type;}
    int getWater () {return _water;}
};


class Plain : public Area {
public:
    Plain(const string &str, const string &t, int w) : Area(str, t, w){}
    void change(Weather* &weather) override {
        weather = weather->change(this);
    }
};


class Grassland : public Area {
public:
    Grassland(const string &str, const string &t, int w) : Area(str, t, w){}
   void change(Weather* &weather) override {
        weather = weather->change(this);
    }
};


class LakesRegion : public Area {
public:
    LakesRegion(const string &str, const string &t, int w) : Area(str, t, w){}
    void change(Weather* &weather) override{
        weather = weather->change(this);
    }
};


#endif // AREA_H_INCLUDED
