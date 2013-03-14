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
