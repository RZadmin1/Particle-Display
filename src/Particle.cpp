// Particle.cpp

#include "Particle.h"
#include <math.h>
#include <stdlib.h>


namespace particlesim {

Particle::Particle(): m_x(0), m_y(0) {
    m_direction = (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.0007 * rand())/RAND_MAX;
}

Particle::~Particle() {
    // TODO: Auto-generated destructor stub
}

void Particle::udpate(int interval) {
    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);

    m_x += xspeed * interval;
    m_y += yspeed * interval;
}

} /* namespace particlesim */