#ifndef FLAG_H
#define FLAG_H
#include "block.h"
#include "particle.h"
/* 2024-12-06 KGD: copy brick.h and changed to to create a flag, may not need*/
class Flag : public Block
{
public:
    static constexpr const float Flag_PARTICLE_SPEED = 250.f;
    static constexpr const float Flag_PARTICLE_FALLDOWN = 10.f;
    static void createFlag(QPointF position);
    Flag(float x, float y);
    virtual ~Flag();
    virtual void draw(GameScene &scene) override;
    virtual void update(float elapsedTime) override;
    void destroy();
    bool isDestroyed() const;
private:
    QPixmap m_FlagPixmap;
    Particle *m_particle[4];
    bool m_isDestroyed;
};

#endif // FLAG_H
