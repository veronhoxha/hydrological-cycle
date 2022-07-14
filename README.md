# hydrological-cycle

- The task:

In the hydrological cycle of the Earth, various areas affect the weather as well as areas are also affected by 
various weathers. Areas involved in the simulation: plain, grassland, lakes region. Each area has a name, and the 
amount of water stored in the certain area is also given in km3
. The humidity of the air over the areas is also given 
in percentage. 

The possible types of weather are the following: sunny, cloudy, rainy, depending on the humidity of the air. In case 
the humidity exceeds 70%, the weather gets rainy and the humidity decreases to 30%.
In case the humidity is between 40-70%, the calculation of the chance of rainy weather is: (humidity-30)*3,3%, 
otherwise the weather is cloudy. Humidity below 40% leads to sunny weather.

In the following, we declare how the certain areas respond to the different type of weathers.
First the amount of water stored by the area varies then the weather will be affected. There is no type of areas with 
negative amount of water stored. 

- In case the type is plain, if the weather is sunny, the amount of water will be decreased by 3 km3
; if cloudy, it 
will be decreased by 1 km3
; for rainy weather it will be increased by 20 km3
. The humidity of the air is increased 
by 5%. If the amount of the stored water is greater than 15 km3
, the plain area changes into grassland.

- In case of type grassland: in sunny weather, the amount of water is decreased by 6 km3
, for cloudy it will be 
decreased by 2 km3
, but and for rainy, it will be increased by 15 km3
. The humidity of the air is increased by 
10%. The area becomes lakes region obtaining amount of water over 50 km3
, whereas in case the amount of 
stored water goes below 16 km3
, the area changes to plain.

- In case of type lakes region: in sunny weather, the amount of water is decreased by 10 km3
, for cloudy it will 
be decreased by 3 km3
, for rainy it will be increased by 20 km3
. The humidity will be increased by 15%. Beyond 
an amount of water of 51 km3
the area changes into grassland.

The program reads data from a text file. The first line of the file contains a single integer N indicating the number 
of areas. Each of the following N lines contains the attributes of an area separated by spaces: the owner of the area, 
the type of the area, and the amount of water stored by the area. In the last line, the humidity of the air is given in 
percentage. The type is identified by a character: P – plain, G – grassland, L – lakes region.

We continue the simulation until each area has the same type. The program should print all attributes of the 
certain areas by simulation rounds!

- NOTES
1. The task is a school homework.
