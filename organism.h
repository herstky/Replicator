#pragma once

#include "entity.h"

#include <QPainter>
#include <QTime>

class Simulation;

class Organism : public Entity 
{
	friend class Simulation;
public:
    Organism(const Simulation& simulation);
    Organism(const Simulation& simulation, const QPointF& position);
    virtual ~Organism() override;

    qreal volume();
    qreal diameter();
    qreal deltaVelocity();
    qreal deltaTime();
    qreal acceleration();

	void move(const Simulation& simulation) override;
	void simulate(Simulation& simulation) override;

	void eat(const Simulation& simulation, Entity& other);

protected:
	qreal mVelocity; // [m/s]
	qreal mInitialVelocity; // [m/s]
	QTime mInitialTime; 
	qreal mDeltaDistance; // [m]
	qreal mDirection; // [rad]
	qreal mReplicationChance;
	qreal mMutationChance;
	qreal mDeathChance;

	qreal mMass; // [kg]
	qreal mDensity; // [kg/m^3]
	qreal mEnergyLevel;
	qreal mEnergyCapacity;

	qreal x() override;
	qreal y() override;
	qreal height() override;
	void setHeight(qreal height) override;
	qreal width() override;
	void setWidth(qreal width) override;
    void expendEnergy(const Simulation& simulation);
	virtual void replicate(const Simulation& simulation);
	virtual QRectF hitbox() override;
	virtual void collide(const Simulation& simulation, Entity& other) override;
};

