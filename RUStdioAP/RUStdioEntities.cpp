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

bool RUStdioEntities::createEntity( void ){

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
		}else if( nodeName == "Rotation" ){
			RUStdioEntities::getRotation( node, ent );
		}
	}
}

//TODO
void RUStdioEntities::getEntityName( pugi::xml_node NodeName, Ogre::Entity* ent ){
}

//TODO 
void RUStdioEntities::getMesh( pugi::xml_node NodeMesh, Ogre::Entity* ent ){
}

//TODO
void RUStdioEntities::getCastShadows( pugi::xml_node NodeCastShadows, Ogre::Entity* ent ){
}

//TODO
void RUStdioEntities::getRotation( pugi::xml_node NodeRotation, Ogre::Entity* ent ){
}