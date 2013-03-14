/*

   libjEngine - C++ 3D library
Copyright (C) 2013  Jacques Rott <jacques.rott@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef __RAND__
#define __RAND__

namespace jE {
    /*
     *  Some random function tools
     */

    /*
     *  Init the random seed with defined seed
     *      seed:   user defined seed
     */
    void    setSeed(const int seed);

    /*
     *  Init the random seed with actual timestamp
     */
    void    initSeed(void);

    /*
     *  Generates a random float between a minimum and maximum
     *      min: minimum return value
     *      max: maximum return value
     *  @return: random float
     */
    float   randFloat(const float min, const float max);

    /*
     *  Generates a random integer between a minimum and maximum
     *      min: minimum return value
     *      max: maximum return value
     *  @return: random integer
     */
    int     randInt(const int min, const int max);

    /*
     *  Generates a random boolean, as a coin toss
     *  @return: random boolean
     */
    bool    randBool(void);
};

#endif
