#pragma once

#include "Model/Model.h"

class Simulation;

class Entity : public Model
{
	friend class Simulation;

public:
	enum class Type { none, predator, prey };

	Entity();
	Entity(const QPointF& pPosition);
	virtual ~Entity() override;

	virtual void simulate(Simulation& pSimulation);
	virtual void train(Simulation& pSimulation);
	virtual void move(const Simulation& pSimulation);
	virtual void detectCollisions(Simulation& pSimulation);
	virtual void collide(Simulation& pSimulation, Entity& pOther);
	virtual void emanateScent();
	virtual qreal scent(const qreal& distance);

	Type getType();
	void setPersistent(bool pPersistent);
	bool persistent();
	qreal getEnergyContent();
	qreal getMass();
	qreal getDensity();
	qreal getAspectRatio();
	qreal getDepth();

	const qreal M_SCENT_STRENGTH;
	const qreal M_SCENT_DIFFUSIVITY;
	const qreal M_SCENT_RETENTION; // What portion of the entity's scent strength remains


protected:
	Type mType;
	bool mPersistent;
	qreal mEnergyContent; // [kJ/kg]
	qreal mMass; // [kg]
	qreal mDensity; // [kg/m^3]
	qreal mAspectRatio; // width/height
	qreal mDepth; // [m]

private:
	Entity(const Entity& pOther);
	Entity& operator=(const Entity& pOther);

};

