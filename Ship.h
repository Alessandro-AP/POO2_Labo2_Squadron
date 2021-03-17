//
// Created by Alessandro on 17.03.2021.
//

#ifndef BASE_SHIP_H
#define BASE_SHIP_H

#include <ostream>
class Ship;
std::ostream& operator << (std::ostream& os, const Ship& ship);
class Ship
{
public:
    virtual ~Ship();
/* à compléter */
    virtual std::ostream& toStream(std::ostream& os) const;
private:
/* à compléter */
};


#endif //BASE_SHIP_H
