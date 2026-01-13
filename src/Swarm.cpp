// Swarm.cpp

#include "Swarm.h"

namespace particlesim {

Swarm::Swarm(): lastTime(0) {
    m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
    delete [] m_pParticles;
}

void Swarm::update(int elapsed) {
    int interval = elapsed - lastTime;
    for (int i = 0, n = Swarm::NPARTICLES; i < n; i++) {
        m_pParticles[i].udpate(interval);
    }
    lastTime = elapsed;
}

} /* namespace particlesim */