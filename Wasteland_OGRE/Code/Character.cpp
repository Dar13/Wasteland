#include "StdAfx.h"

#include "Character.h"
#include "Utility.h"

Character::Character(const std::string& name,Ogre::SceneManager* scene,CrowdManager* crowd,const Ogre::Vector3& position)
{
	//won't use this often.
}

Character::Character(Ogre::SceneNode* node,CrowdManager* crowd,const Ogre::Vector3& position)
	: _node(nullptr),
	  _movableObject(nullptr),
	  _agentID(-1),
	  _agent(nullptr),
	  _isStopped(false),
	  _isAgentControlled(true),
	  _crowd(crowd)
{
	_agentID = _crowd->addAgent(position);
	_agent = _crowd->getAgent(_agentID);
}

void Character::setPosition(const Ogre::Vector3& position)
{
	if(!_isAgentControlled)
	{
		_node->setPosition(position);
		return;
	}
	
	Ogre::Vector3 result;
	if(!_crowd->_getDetour()->findNearestPointOnNavmesh(position,result))
	{
		return;
	}

	_crowd->removeAgent(_agentID);
	_agentID = _crowd->addAgent(result);

	_node->setPosition(result);
}

Ogre::Vector3 Character::getPosition()
{
	_node->getPosition();
}

bool Character::destinationReached()
{
	return (_node->getPosition().squaredDistance(getDestination()) <= _destRadius);
}

void Character::setVelocity(const Ogre::Vector3& velocity)
{
	_manualVelocity = velocity;
	_isStopped = false;
	_destination = Ogre::Vector3::ZERO;

	if(_isAgentControlled)
	{
		_crowd->requestVelocity(_agentID,_manualVelocity);
	}
}

Ogre::Vector3 Character::getVelocity()
{
	if(_isAgentControlled)
	{
		Ogre::Vector3 vel;
		Utility::floatPtr_toVector3(_agent->nvel,vel);
		return vel;
	}
	else
	{
		return _manualVelocity;
	}
}

void Character::stop()
{
	if(_isAgentControlled && _crowd->stopAgent(_agentID))
	{
		_destination = Ogre::Vector3::ZERO;
	}
	
	_manualVelocity = Ogre::Vector3::ZERO;
	_isStopped = true;
	return;
}

float Character::getSpeed()
{
	return getVelocity().length();
}

float Character::getMaxSpeed()
{
	return _agent->params.maxSpeed;
}

float Character::getMaxAcceleration()
{
	return _agent->params.maxAcceleration;
}

bool Character::isMoving()
{
	return !_isStopped || getSpeed() != 0;
}

Ogre::Vector3 Character::getLookingDirection()
{
	return _node->getOrientation() * Ogre::Vector3::NEGATIVE_UNIT_Z;
}

void Character::setAgentControlled(bool agentControlled)
{
	if(_isAgentControlled != agentControlled)
	{
		if(agentControlled)
		{
			_agentID = _crowd->addAgent(_node->getPosition());
			_agent = _crowd->getAgent(_agentID);
			_destination = _crowd->getLastDestination();
			_manualVelocity = Ogre::Vector3::ZERO;
			_isStopped = true;
		}
		else
		{
			_crowd->removeAgent(_agentID);
			_agentID = -1;
			_destination = Ogre::Vector3::ZERO;
			_isStopped = false;
		}
		_isAgentControlled = agentControlled;
	}
	return;
}