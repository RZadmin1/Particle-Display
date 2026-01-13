// Particle.h

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particlesim {

/* STRUCT vs. CLASS
 * Only difference between CLASS and STRUCT 
 * is that STRUCT has members Public by default
 */

struct Particle {

    double m_x;
    double m_y;

    double m_speed;
    double m_direction;

public:
    Particle();
    virtual ~Particle();
    void udpate(int interval);
};

} /* namespace particlesim */

#endif /* PARTICLE_H_ */