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

#ifndef __JMATH__
#define __JMATH__

namespace jE {
    /*
     *  Math tools
     */
    
    /*
     * Converts a degrees angle to radian
     *        d: degrees angle
     *  @return: double randian angle
     */
    double radians(double d);
    
    /*
     * Converts a randian angle to degrees
     *        r: randian angle
     *  @return: double degrees angle
     */    
    double degrees(double r);

    /*
     * Converts a degrees angle to radian
     *        d: degrees angle
     *  @return: float randian angle
     */    
    float  radiansf(float d);

    /*
     * Converts a randian angle to degrees
     *        r: randian angle
     *  @return: float degrees angle
     */
    float  degreesf(float r);
};

#endif
