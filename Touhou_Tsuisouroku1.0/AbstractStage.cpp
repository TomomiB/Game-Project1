#include "AbstractStage.h"

AbstractStage::AbstractStage()
{
	counter = 0;
}

void AbstractStage::update()
{
	counter++;
}

void AbstractStage::draw() const
{

}