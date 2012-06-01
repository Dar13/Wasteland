#include "StdAfx.h"

#include "Arena_Tutorial.h"
#include "GameManager.h"
#include "debug\console.h"
#include "Utility.h"
#include <boost\lexical_cast.hpp>

#include "LuaManager.h"

ArenaTutorial::ArenaTutorial()
{
	_camera = 0;
	_scene = 0;
	_rootNode = 0;
	_stateShutdown = false;
	_view = 0;
	_deltaTime = 0;
	_oldTime = 0;
}

void ArenaTutorial::Setup(InputManager* Input,GraphicsManager* Graphics,GUIManager* Gui,SoundManager* Sound)
{
	_scene = Graphics->getRoot()->createSceneManager(Ogre::ST_INTERIOR,"arenaTut");

	_camera = _scene->createCamera("arenaTutCam");
	_camera->setAspectRatio(16.0f/9.0f);
	_view = Graphics->getRenderWindow()->addViewport(_camera);
	_view->setBackgroundColour(Ogre::ColourValue(0,0,0));

	_rootNode = _scene->getRootSceneNode();

	//physics setup
	_physics.reset(new PhysicsManager() );
	_physics->Setup();
	_physics->setGravity(btVector3(0.0f,-9.8f,0.0f));

	//using a list instead of hardcoded files
	std::auto_ptr<list_t> objList = list("resource\\xml\\lists\\arena_list.xml");
	for(list_t::file_const_iterator itr = objList.get()->file().begin(); itr != objList.get()->file().end(); ++itr)
	{
		std::string tmp = (*itr);
		_pairs.push_back(GameManager::createObject(_scene,tmp,_physics.get(),Graphics));
	}

	//camera setup
	_camera->setPosition(Ogre::Vector3(-30,1.9f,0));
	_camera->setNearClipDistance(.001f);
	_camera->setFarClipDistance(1000.0f);
	_camera->lookAt(0,1.8f,0);

	//player setup
	_player.reset(new Player());
	
	//set the camera aspect ratio
	_camera->setAspectRatio(16.0f/9.0f);
	//wireframe
	_camera->setPolygonMode(Ogre::PM_WIREFRAME);

	//let's try out the character controller
	_controller.reset(new CharacterController(_camera,_camera->getPosition(),_physics->getWorld(),Graphics ) );
	//since we're using the character controller, should also lock the mouse.
	Input->setMouseLock(true);

	//let's setup the EWS system
	_ews.reset(new EWSManager(_scene));

	//std::string value = "20,0,5";

	LevelData::LevelParser parser;
	parser.setFile("resource\\models\\mapscapeTEST\\zonedoor_scriptTest.ent");
	parser.parseDoors(&_doors);
	parser.parseLights(&_lights);
	parser.parseTriggers(&_triggers);

	_setupLights(Graphics,_scene);
	OgreBulletPair level = _pairs.at(1);
	_setupDoors(level,_scene,_physics.get(),Graphics);

	//attempt to make a door out of a hinge constraint in bullet.
	//get the last ogrebulletpair
	/*
	OgreBulletPair hinge1 = _pairs.at(_pairs.size()-2);
	
	hinge1.btBody->setActivationState(DISABLE_DEACTIVATION);
	btHingeConstraint* hingeDoor;
	hingeDoor = new btHingeConstraint(*level.btBody,*hinge1.btBody,btVector3(20.5f,5.0f,-5.0f),btVector3(0.0f,0.0f,-5.0f),btVector3(0,1,0),btVector3(0,1,0));
	_physics->getWorld()->addConstraint(hingeDoor,true);
	hingeDoor->setLimit(-0.1f,SIMD_PI / 2);
	_constraints.push_back(hingeDoor);
	*/

	//physics debug drawer.
	//_physics->setDebugDrawer(new CDebugDraw(_scene,_physics->getWorld()));
}

int ArenaTutorial::Run(InputManager* Input,GraphicsManager* Graphics,GUIManager* Gui,SoundManager* Sound)
{
	_stateShutdown=false;
	Ogre::SceneNode* tmpNode = (Ogre::SceneNode*)_scene->getRootSceneNode()->getChild("nodetestSphere");

	OgreTransform playerTransform;
	
	float time;
	//while the escape key isn't pressed and the state isn't told to shutdown.
	while(!_stateShutdown)
	{
		//current time
		time = static_cast<float>(Graphics->getTimer()->getMilliseconds());
		//getting the delta time
		_deltaTime = time - _oldTime;
		//setting the old time
		_oldTime = time;

		//the state shutdown based on player input(?)
		_stateShutdown = Input->Update(true);

		//Update the character controller
		_controller->update(_deltaTime,Input,playerTransform);

		//Update Player-specific stuff
		_player->Update(Input,_physics.get(),_ews.get(),playerTransform);

		//Update the EWS system
		_ews->Update(100,static_cast<int>(time),Input->isCFGKeyPressed(ENVWARNSYS),playerTransform);

		//True indicates success, so react on if it doesn't react properly
		if(!GameManager::UpdateManagers(Graphics,_physics.get(),_deltaTime))
			_stateShutdown = true;

		_updateLights();
		_updateTriggers(playerTransform,static_cast<int>(time));
		_updateDoors();
	}

	//no matter what, end the program after this state. **TESTING ONLY**
	return END;
}

//clean-up of state
void ArenaTutorial::Shutdown(InputManager* Input,GraphicsManager* Graphics,GUIManager* Gui,SoundManager* Sound)
{
	//undo what I set in OIS
	Input->setMouseLock(false);

	//clean up what you initialized in the Setup() function.
	Graphics->getRenderWindow()->removeAllViewports();
	
	//Destroy the camera, since we've taken care of the viewport.
	_scene->destroyCamera(_camera);
	//Destroy all SceneNodes, Entites, etc.
	_scene->clearScene();

	//Set to null.
	_rootNode=0;

	//Clear the vectors
	_nodes.clear();
	_entities.clear();

	//I'm clearing them due to physicsManager clean-up.
	_constraints.clear();

	//cleaning up state-specific pointers.
	//since all pointers are auto_ptr members, then they will be deleted upon class destruction.

	//Destroy the scene manager.
	Graphics->getRoot()->destroySceneManager(_scene);
}

void ArenaTutorial::_setupLights(GraphicsManager* g, Ogre::SceneManager* scene)
{
	for(auto itr = _lights.begin(); itr != _lights.end(); ++itr)
	{
		switch((*itr)->getLightType())
		{
		case Ogre::Light::LT_SPOTLIGHT:
			static_cast<LevelData::SpotLightData*>((*itr).get())->createLight(scene,g);
			break;
		case Ogre::Light::LT_POINT:
			static_cast<LevelData::PointLightData*>((*itr).get())->createLight(scene,g);
			break;
		case Ogre::Light::LT_DIRECTIONAL:
			static_cast<LevelData::DirectionalLightData*>((*itr).get())->createLight(scene,g);
			break;
		};
	}
}

void ArenaTutorial::_updateLights()
{
	for(auto itr = _lights.begin(); itr != _lights.end(); ++itr)
	{
		(*itr)->update();
	}
}

void ArenaTutorial::_updateTriggers(OgreTransform& playerTransform, int currentTime)
{
	for(auto itr = _triggers.begin(); itr != _triggers.end(); ++itr)
	{
		switch((*itr)->getTriggerType())
		{
		case LevelData::PLAYER:
			static_cast<LevelData::PlayerTrigger*>((*itr).get())->update(playerTransform);
			break;
		case LevelData::ENTITY:
			static_cast<LevelData::EntityTrigger*>((*itr).get())->update();
			break;
		case LevelData::TIME:
			static_cast<LevelData::TimeTrigger*>((*itr).get())->update(currentTime);
			break;
		};
	}
}

void ArenaTutorial::_setupDoors(OgreBulletPair& mainLevel,Ogre::SceneManager* scene,PhysicsManager* p,GraphicsManager* g)
{
	for(auto itr = _doors.begin(); itr != _doors.end(); ++itr)
	{
		(*itr)->createDoor(scene,g,p,&mainLevel);
		LuaManager::getSingleton().addEntity((*itr)->getName(),(*itr).get());
	}
}

void ArenaTutorial::_updateDoors()
{
	for(std::vector<std::unique_ptr<LevelData::DoorData>>::iterator itr = _doors.begin(); itr != _doors.end(); ++itr)
	{
		(*itr)->update();
	}
}