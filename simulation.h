#pragma once

#include <QQuickItem>
#include <QTimer>
#include <QTime>
#include <QObject>
#include <QRandomGenerator>
#include <QFuture>

#include <vector>
#include <unordered_set>
#include <memory>

#include "utils.h"
#include "organism.h"
#include "board.h"
#include "scentsystem.h"

using coordPair = std::pair<int, int>;
using coordMap = std::unordered_map<coordPair, qreal, pair_hash>;

class Simulation : QObject
{
	Q_OBJECT
public:
	enum class Mode { debug, train, simulate };

	friend class Entity;
	friend class Food;
	friend class Organism;
    
	Simulation(QQuickItem* pParent);
    Simulation(QQuickItem* pParent, Mode pMode);
	
	QQuickItem& mContainer;

	void addOrganism(std::shared_ptr<Organism> pOrganism);
	void addOrganismGroup(std::vector<std::shared_ptr<Organism>> pGroup);
	void addFood(std::shared_ptr<Food> pFood);
	void removeFood(std::shared_ptr<Food> pFood);
	qreal getScent(coordPair pCoords);
	std::shared_ptr<QQuickItem> boardView() const;
	qreal deltaTime() const;
	Board& board();
	void simulate();
	void train();
	

public slots:
    void run();

protected:
	void init();

private:
	Mode mMode;
	Board mBoard;
	ScentSystem mScentSystem;
	coordMap mScentMap;
	QFuture<void> mDiffusionThread;
    const int M_TICK_DURATION; // [ms]
    const int M_TICKS_PER_STEP; // simulate only called every step
    int mTicksRemaining;
	QTime mInitialTime; // time since previous step
	std::unordered_set<std::shared_ptr<Food>> mFoodSet;
	std::vector<std::vector<std::shared_ptr<Organism>>> mOrganismGroups;
	std::vector<std::shared_ptr<Entity>> mInitViewQueue;
	coordMap mScentQueue;
	void outputCounts();
};
