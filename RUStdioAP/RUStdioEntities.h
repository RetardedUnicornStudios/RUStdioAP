#include <OgreEntity.h>
#include <OgreRoot.h>
#include <OgreLogManager.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>
#include <pugiconfig.hpp>
#include <pugixml.hpp>

class RUStdioEntities : public Ogre::FrameListener{
public:
	RUStdioEntities( void );
	virtual ~RUStdioEntities( void );

protected:
	virtual bool createEntity( void );
	virtual void setEntityProperties( Ogre::Entity* ent, pugi::char_t* name );
	virtual void getEntityName( pugi::xml_node NodeName, Ogre::Entity* ent );
	virtual void getMesh( pugi::xml_node NodeMesh, Ogre::Entity* ent );
	virtual void getCastShadows( pugi::xml_node NodeCastShadows, Ogre::Entity* ent );
	virtual void getRotation( pugi::xml_node NodeRotation, Ogre::Entity* ent );

	Ogre::Root* mRoot;
	Ogre::SceneManager* mSceneMgr;
    Ogre::RenderWindow* mWindow;
    Ogre::String mResourcesCfg;
    Ogre::String mPluginsCfg;
};