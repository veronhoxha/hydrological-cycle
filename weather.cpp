#include "weather.h"
#include "area.h"

using namespace std;

Sunny* Sunny::_instance = nullptr;
Sunny* Sunny::instance(int &h)
{
    _instance = new Sunny(h);
}
void Sunny::destroy()
{
	if ( nullptr!=_instance )
	{
		delete _instance;
		_instance = nullptr;
	}
}

Weather* Sunny::change(Plain *p)
{
    p->changeWater(-3);

    if(this->humidity > 70) {
        this->humidity = 35;
            if(this->humidity == 35)
            {
                return Sunny::instance(this->humidity);
            }
        else
        return Rainy::instance(this->humidity);
    }
    this->humidity += 5;
        if(this->humidity > 70) {
            return Rainy::instance(this->humidity);
    }

    else {
        if (40<=this->humidity && this->humidity<=70) {
        if ((this->humidity-30)*3.3 >= 100) {
            return Rainy::instance(this->humidity);

        } else
            return Cloudy::instance(this->humidity);
        }
        else {
           return Sunny::instance(this->humidity);
        }
    }
}

Weather* Sunny::change(Grassland *p)
{
    p->changeWater(-6);

    if(this->humidity > 70) {
        this->humidity = 40;
            if(this->humidity == 40)
            {
                return Cloudy::instance(this->humidity);
            }
        else
        return Rainy::instance(this->humidity);
    }
      this->humidity += 10;
         if(this->humidity > 70) {
            return Rainy::instance(this->humidity);
    }
    else {
        if (40<=this->humidity && this->humidity<=70) {
        if ((this->humidity-30)*3.3 >= 100) {
            return Rainy::instance(this->humidity);

        } else
            return Cloudy::instance(this->humidity);
        }
        else {
           return Sunny::instance(this->humidity);
        }
    }
}

Weather* Sunny::change(LakesRegion *p)
{
    p->changeWater(-10);

    if(this->humidity > 70) {
        this->humidity = 45;
            if(this->humidity == 45)
            {
                return Cloudy::instance(this->humidity);
            }
        else
        return Rainy::instance(this->humidity);
    }
    this->humidity += 15;
        if(this->humidity > 70) {
            return Rainy::instance(this->humidity);
    }
    else {
        if (40<=this->humidity && this->humidity<=70) {
        if ((this->humidity-30)*3.3 >= 100) {
            return Rainy::instance(this->humidity);

        } else
            return Cloudy::instance(this->humidity);
        }
        else {
           return Sunny::instance(this->humidity);
        }
    }
}

////////////////////////////////////////////////////////////////

Cloudy* Cloudy::_instance = nullptr;
Cloudy* Cloudy::instance(int &h)
{
    _instance = new Cloudy(h);

}
void Cloudy::destroy()
{
	if ( nullptr!=_instance )
	{
		delete _instance;
		_instance = nullptr;
	}
}

Weather* Cloudy::change(Plain *p)
{
    p->changeWater(-1);

    if(this->humidity > 70) {
        this->humidity = 35;
            if(this->humidity == 35)
            {
                return Sunny::instance(this->humidity);
            }
        else
        return Rainy::instance(this->humidity);
    }
     this->humidity += 5;
     if(this->humidity > 70) {
        return Rainy::instance(this->humidity);
    }
    else {
     if (40<=this->humidity && this->humidity<=70) {
        if ((this->humidity-30)*3.3 >= 100) {
            return Rainy::instance(this->humidity);

        } else
            return Cloudy::instance(this->humidity);
        }
        else {
           return Sunny::instance(this->humidity);
        }
    }
}

Weather* Cloudy::change(Grassland *p)
{
    p->changeWater(-2);

    if(this->humidity > 70) {
        this->humidity = 40;
            if(this->humidity == 40)
            {
                return Cloudy::instance(this->humidity);
            }
        else
        return Rainy::instance(this->humidity);
    }
     this->humidity += 10;
       if(this->humidity > 70) {
        return Rainy::instance(this->humidity);
    }
    else {
        if (40<=this->humidity && this->humidity<=70) {
            if ((this->humidity-30)*3.3 >= 100) {
                return Rainy::instance(this->humidity);
            } else
                return Cloudy::instance(this->humidity);
            }
        else {
           return Sunny::instance(this->humidity);
        }
    }
}

Weather* Cloudy::change(LakesRegion *p)
{
    p->changeWater(-3);

    if(this->humidity > 70) {
        this->humidity = 45;
            if(this->humidity == 45)
            {
                return Cloudy::instance(this->humidity);
            }
        else
        return Rainy::instance(this->humidity);
    }
    this->humidity += 15;
        if(this->humidity > 70) {
            return Rainy::instance(this->humidity);
    }
    else {
        if (40<=this->humidity && this->humidity<=70) {
        if ((this->humidity-30)*3.3 >= 100) {
            return Rainy::instance(this->humidity);

        } else
            return Cloudy::instance(this->humidity);
        }
        else {
           return Sunny::instance(this->humidity);
        }
    }
}

////////////////////////////////////////////////////////////////

Rainy* Rainy::_instance = nullptr;
Rainy* Rainy::instance(int &h)
{
    _instance = new Rainy(h);

}
void Rainy::destroy()
{
	if ( nullptr!=_instance )
	{
		delete _instance;
		_instance = nullptr;
	}
}

Weather* Rainy::change(Plain *p)
{
    p->changeWater(20);

    if(this->humidity > 70) {
        this->humidity = 35;
            if(this->humidity == 35)
            {
                return Sunny::instance(this->humidity);
            }
        else
        return Rainy::instance(this->humidity);
    }
    this->humidity += 5;
          if(this->humidity > 70) {
          return Rainy::instance(this->humidity);
          }
    else {
        if (40<=this->humidity && this->humidity<=70) {
            if ((this->humidity-30)*3.3 >= 100) {
                return Rainy::instance(this->humidity);

            } else
                return Cloudy::instance(this->humidity);
        }
        else {
           return Sunny::instance(this->humidity);
        }
    }
}

Weather* Rainy::change(Grassland *p)
{
    p->changeWater(15);

   if(this->humidity > 70) {
        this->humidity = 40;
            if(this->humidity == 40)
            {
                return Cloudy::instance(this->humidity);
            }
        else
        return Rainy::instance(this->humidity);
    }
       this->humidity += 10;
          if(this->humidity > 70) {
          return Rainy::instance(this->humidity);
    }
    else {
        if (40<=this->humidity && this->humidity<=70) {
            if ((this->humidity-30)*3.3 >= 100) {
                return Rainy::instance(this->humidity);

            } else
                return Cloudy::instance(this->humidity);
            }
        else {
           return Sunny::instance(this->humidity);
        }
    }
}

Weather* Rainy::change(LakesRegion *p)
{
    p->changeWater(20);

    if(this->humidity > 70) {
        this->humidity = 45;
            if(this->humidity == 45)
            {
                return Cloudy::instance(this->humidity);
            }
        else
        return Rainy::instance(this->humidity);
    }
    this->humidity += 15;
       if(this->humidity > 70) {
        return Rainy::instance(this->humidity);
    }
    else {
        if (40<=this->humidity && this->humidity<=70) {
        if ((this->humidity-30)*3.3 >= 100) {
            return Rainy::instance(this->humidity);

        } else
            return Cloudy::instance(this->humidity);
        }
        else {
           return Sunny::instance(this->humidity);
        }
    }
}
