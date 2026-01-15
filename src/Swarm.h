// Swarm.h

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace particlesim {

class Swarm {

public:
    const static int NPARTICLES = 3500;

private:
    Particle *m_pParticles;
    int lastTime;

public:
    Swarm();
    virtual ~Swarm();
    void update(int elapsed);
    const Particle * const getParticles() { return m_pParticles; };
};

} /* namespace particlesim */

#endif /* SWARM_H_ */