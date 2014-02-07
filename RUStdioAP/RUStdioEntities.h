#include <OgreEntity.h>
#include <OgreRoot.h>
#include <OgreSceneNode.h>
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
	virtual bool createSceneNode( void );
	virtual void setEntityProperties( Ogre::Entity* ent, pugi::char_t* name );
	virtual void setSceneNodeProperties( Ogre::SceneNode* scnNode, pugi::char_t* name );
	virtual Ogre::String getEntityName( pugi::xml_node nodeName, Ogre::Entity* ent );
	virtual Ogre::String getSceneNodeName( pugi::xml_node nodeName, Ogre::SceneNode* scnNode );
	virtual Ogre::String getMesh( pugi::xml_node NodeMesh, Ogre::Entity* ent );
	virtual void getCastShadows( pugi::xml_node NodeCastShadows, Ogre::Entity* ent );
	virtual void getRotation( float fPitch, float fYaw, float fRoll, Ogre::SceneNode* scnNode );

	Ogre::Root* mRoot;
	Ogre::SceneManager* mSceneMgr;
    Ogre::RenderWindow* mWindow;
    Ogre::String mResourcesCfg;
    Ogre::String mPluginsCfg;
};