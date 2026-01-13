// Swarm.cpp

#include "Swarm.h"

namespace particlesim {

Swarm::Swarm() {
    m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
    delete [] m_pParticles;
}

void Swarm::update() {
    for (int i = 0, n = Swarm::NPARTICLES; i < n; i++) {
        m_pParticles[i].udpate();
    }
}

} /* namespace particlesim */