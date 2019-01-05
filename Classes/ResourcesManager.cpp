//
//  ResourcesManager.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/2/19.
//

#include "ResourcesManager.h"
#include "Object.h"

ResourcesManager::ResourcesManager()
{
    init();
}

ResourcesManager::~ResourcesManager()
{
    _listgObjects.clear();
    _listgObjectCreated.clear();
}

void ResourcesManager::init()
{
    //init list object
    _listgObjects[object::CIRCLE] = [this](const string& s){ return this->createObject(s); };
    _listgObjects[object::HOLE] = _listgObjects[object::CIRCLE];
    
    
}

shared_ptr<gObject> ResourcesManager::getObject(const string& value)
{
    shared_ptr<gObject> obj = _listgObjects[value](value);
    
    return obj;
}

shared_ptr<gObject> ResourcesManager::createObject(const string& path)
{
    shared_ptr<gObject> obj = make_shared<gObject>(path.c_str());
    
    return obj;
}

shared_ptr<gObject> ResourcesManager::getObjectCreated(const string& key)
{
    return _listgObjectCreated[key];
}
