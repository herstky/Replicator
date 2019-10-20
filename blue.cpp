#include "blue.h"

#include "simulation.h"
#include "green.h"

unsigned int Blue::mCount = 0;
qreal Blue::mCreationChance = 0;

Blue::Blue()
{
	init();
}

Blue::Blue(const QPointF& pPosition)
	: Organism(pPosition)
{
	init();
}

Blue& Blue::operator=(const Blue& pOther)
{
	return *this;
}

Blue::~Blue() {}

void Blue::replicate(const Simulation& pSimulation) {}

void Blue::die(const Simulation& pSimulation)
{
	Model::die(pSimulation);
	mCount--;
}

void Blue::init()
{
	mType = Entity::Type::predator;
	mShape = Model::Shape::ellipse;
	mColor = Qt::blue;
	mReplicationChance = 4;
	mMutationChance = 0;
	mDeathChance = 3;
	mCount++;
}
