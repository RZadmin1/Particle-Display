// Particle.cpp

#include "Particle.h"
#include <stdlib.h>


namespace particlesim {

Particle::Particle() {
    m_x = ((2.0 * (double)rand())/RAND_MAX) - 1;
    m_y = ((2.0 * (double)rand())/RAND_MAX) - 1;
}

Particle::~Particle() {
    // TODO: Auto-generated destructor stub
}

void Particle::udpate() {
    const double speed = 0.01;

    m_x += speed;
    m_y += speed;
}

} /* namespace particlesim */