/*
===============================================================================

	Filename:	RUStdioEntities.cpp
	Implements functionality to the generation of OGRE3D entities by
	parsing an xml file

===============================================================================
*/

#include "RUStdioEntities.h"

RUStdioEntities::RUStdioEntities( void )
	: mRoot( 0 ),
	mSceneMgr( 0 ),
	mWindow( 0 ),
	mResourcesCfg( Ogre::StringUtil::BLANK ),
	mPluginsCfg( Ogre::StringUtil::BLANK ){
}

RUStdioEntities::~RUStdioEntities( void ){
	delete mRoot;
}

//TODO
bool RUStdioEntities::createEntity( void ){

}

//TODO
bool RUStdioEntities::createSceneNode( void ){

}

/*
====================
setSceneNodeProperties

  Parses an xml file to set the scene node attributes
====================
*/
void RUStdioEntities::setSceneNodeProperties( Ogre::SceneNode* scnNode, pugi::char_t* nem ){
}

/*
====================
setEntityProperties

  Parses an xml file to set the entity attributes
====================
*/
void RUStdioEntities::setEntityProperties( Ogre::Entity* ent, pugi::char_t* name ){
	pugi::xml_document xmlDoc;
	if( !xmlDoc.load( name ) ){
		std::cerr<< "Error al cargar el documento XML." << std::endl;
		return;		
	}
	pugi::xml_node nodeRoot;
	if( !( nodeRoot = xmlDoc.child( "Properties" ) ) ){
		std::cerr<< "El documento no es un XML válido. " << std::endl;
		return;
	}
	for( pugi::xml_node node = nodeRoot.first_child(); node; node = node.next_sibling() ){
		std::string nodeName = node.name();
		if( nodeName == "Name" ){
			RUStdioEntities::getEntityName( node, ent );
		}else if( nodeName == "Mesh" ){
			RUStdioEntities::getMesh( node, ent );
		}else if( nodeName == "CastShadows" ){
			RUStdioEntities::getCastShadows( node, ent );
		}
	}
}

/*
====================
getEntityName

  Returns the name of the entity
====================
*/
Ogre::String RUStdioEntities::getEntityName( pugi::xml_node nodeName, Ogre::Entity* ent ){
	Ogre::String strNodeName = nodeName.name();
	return strNodeName;
}

/*
====================
getSceneNodeName

  Returns the name of the scene node
====================
*/
Ogre::String RUStdioEntities::getSceneNodeName( pugi::xml_node nodeName, Ogre::SceneNode* scnNode ){
	Ogre::String strNodeName = nodeName.name();
	return strNodeName;
}

/*
====================
getMesh

  Gets the value from the xml file and sets the mesh to the entity
====================
*/
Ogre::String RUStdioEntities::getMesh( pugi::xml_node nodeMesh, Ogre::Entity* ent ){
	Ogre::String strNodeMesh = nodeMesh.value();	
	return strNodeMesh;
}

/*
====================
getCastShadows

  Gets the value from the xml file and sets to an entity the ability of
  cast shadows
====================
*/
void RUStdioEntities::getCastShadows( pugi::xml_node nodeCastShadows, Ogre::Entity* ent ){
	Ogre::String strNodeCastShadows = nodeCastShadows.value();
	bool castShadows;
	if( strNodeCastShadows == "True" ){
		castShadows = true;
	}else{
		castShadows = false;
	}
	ent->setCastShadows( castShadows );
}

/*
====================
getRotation

  Gets the value from the xml file and sets to the rotation in the xyz
  axis of the defined Scene Node
====================
*/
void RUStdioEntities::getRotation( float fPitch, float fYaw, float fRoll, Ogre::SceneNode* scnNode ){
	getPitch( fPitch, scnNode );
	getYaw( fYaw, scnNode );
	getRoll( fRoll, scnNode );
}

#pragma region Helper_functions
/*
====================
getPitch

  Auxiliar method that rotates the the x axis of the Scene Node
====================
*/
void getPitch( float fPitch, Ogre::SceneNode* scnNode ){
	scnNode->pitch( Ogre::Degree( fPitch ) );
}

/*
====================
getPitch

  Auxiliar method that rotates the the y axis of the Scene Node
====================
*/
void getYaw( float fYaw, Ogre::SceneNode* scnNode ){
	scnNode->yaw( Ogre::Degree( fYaw ) );

}

/*
====================
getPitch

  Auxiliar method that rotates the the z axis of the Scene Node
====================
*/
void getRoll( float fRoll, Ogre::SceneNode* scnNode ){
	scnNode->roll( Ogre::Degree( fRoll ) );
}
#pragma endregion Helper_functions