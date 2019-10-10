#pragma once

#include "organism.h"

class Blue : public Organism
{
	friend class Simulation;

public:
    Blue(const Simulation& simulation);
    Blue(const Simulation& simulation, const QPointF& position);
    ~Blue() override;
    
    void replicate(const Simulation& simulation) override;

protected:
	virtual void init() override;

private:
	static unsigned int mCount;
	static qreal mCreationChance;
};
