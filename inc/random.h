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
