#ifndef _ARENA_TUTORIAL_H_
#define _ARENA_TUTORIAL_H_

#include "State.h"

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreCamera.h>
#include <OgreMesh.h>

#include <vector>

/*! \brief Application state that is the Tutorial scene in Wasteland.

Teaches player how to move, shoot, and adds some background to the story. 
Shows a more personal experience of the world that the protagonist is in.
*/

class ArenaTutorial : public State
{
public:
	//! Constructor, initializes all class variables.
	ArenaTutorial();

	//! State-specific setup.
	void Setup();
	//! Runs the state.
	int Run();
	//! Shutsdown and cleans up the application state.
	void Shutdown();

private:
	bool _stateShutdown;

	//! State-specific Ogre::Camera*
	Ogre::Camera* _camera;
	
	//! State-specific Ogre viewport.
	Ogre::Viewport* _view;

	//! State-specific Ogre SceneManager. Allows for greater performance tweaking.
	Ogre::SceneManager* _scene;
	//Scene node stuff
	Ogre::SceneNode* _rootNode;
	std::vector<Ogre::SceneNode*> _nodes;

	//Entity management
	std::vector<Ogre::Entity*> _entities;

};

#endif