#include <reflection/reflectionregistry.h>
#include <osgShadow/ShadowedScene>
#include <stdexcept>

/**
 * Reflector of class osgShadow::ShadowedScene
 */
class RefosgShadowShadowedScene: public ClassReflection {
public:
	RefosgShadowShadowedScene();
	virtual osg::Object *getObject() { return _object.get(); }
	virtual void setObject(osg::Object *obj);
	virtual const std::string &getType() const { return _class_name; }
	virtual const std::string &getOSGVersion() const { return _osg_version; }
	virtual const std::string &getDescription() const { return _class_description; }
	virtual unsigned getNumProperties() const { return _names.size(); }
	virtual const PropertyNames &getPropertyNames() { return _names; }
	virtual void addChild(osg::Object *child);
	virtual void removeChild(osg::Object *child);
	virtual unsigned getNumChildren();
	virtual osg::Object *getChildObject(unsigned i);
	virtual PropertyReflection *getProperty(const std::string &name);
	virtual PropertyReflection *getTableProperty(const std::string &name, unsigned row, unsigned col);
	virtual unsigned getNumTablePropertyColumns(const std::string &name);
	virtual unsigned getNumTablePropertyRows(const std::string &name);
	virtual const PropertyNames &getTablePropertyNames() { return _table_names; }
	virtual const PropertyNames getTablePropertyColumnTitles(const std::string &name);
	virtual const PropertyNames getTablePropertyRowTitles(const std::string &name);
private:
	osg::ref_ptr<osgShadow::ShadowedScene> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_initialBound","_userData","_receivesShadowTraversalMask","_nodeMask","_castsShadowTraversalMask","_cullingActive","_shadowTechnique","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgShadowShadowedScene::_names(_propnames, _propnames+10);

ClassReflection::PropertyNames RefosgShadowShadowedScene::_table_names;

std::string RefosgShadowShadowedScene::_class_name("osgShadow::ShadowedScene");

std::string RefosgShadowShadowedScene::_class_description(" ShadowedScene provides a mechansim for decorating a scene that the needs to have shadows cast upon it.     ");

std::string RefosgShadowShadowedScene::_osg_version("1.2");


/**********************************************************/
RefosgShadowShadowedScene::RefosgShadowShadowedScene() {
}

/**********************************************************/
void RefosgShadowShadowedScene::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgShadow::ShadowedScene*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osgShadow;
using namespace osg;

/**********************************************************/
void RefosgShadowShadowedScene::addChild(osg::Object *child) {
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(cobj);
		return;
	}}
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->addChild(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgShadowShadowedScene::removeChild(osg::Object *child) {
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(0);
		return;
	}}
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->removeChild(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgShadowShadowedScene::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getStateSet();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getCullCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getUpdateCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getEventCallback();
	} else {
		i -= 1;
	}
	if (i < _object->getNumChildren()) {
		return _object->getChild(i);
	} else {
		i -= _object->getNumChildren();
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgShadowShadowedScene::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgShadowShadowedScene::getProperty(const std::string &name) {
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgShadow::ShadowedScene::getInitialBound, &osgShadow::ShadowedScene::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgShadow::ShadowedScene::getUserData, &osgShadow::ShadowedScene::setUserData);
	}
	if (name == "_receivesShadowTraversalMask") {
		return new GetterSetterProperty<unsigned int, osgShadow::ShadowedScene>("_receivesShadowTraversalMask", _object.get(), &osgShadow::ShadowedScene::getReceivesShadowTraversalMask, &osgShadow::ShadowedScene::setReceivesShadowTraversalMask);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgShadow::ShadowedScene::getNodeMask, &osgShadow::ShadowedScene::setNodeMask);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgShadow::ShadowedScene::getName, (setNameFN)&osgShadow::ShadowedScene::setName);
	}
	if (name == "_castsShadowTraversalMask") {
		return new GetterSetterProperty<unsigned int, osgShadow::ShadowedScene>("_castsShadowTraversalMask", _object.get(), &osgShadow::ShadowedScene::getCastsShadowTraversalMask, &osgShadow::ShadowedScene::setCastsShadowTraversalMask);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgShadow::ShadowedScene::getCullingActive, &osgShadow::ShadowedScene::setCullingActive);
	}
	if (name == "_shadowTechnique") {
		// Getter overloaded, must specify one type
		typedef ShadowTechnique * (osgShadow::ShadowedScene::*getShadowTechniqueFN)() ;
		return new GetterSetterProperty<ShadowTechnique*, osgShadow::ShadowedScene>("_shadowTechnique", _object.get(), (getShadowTechniqueFN)&osgShadow::ShadowedScene::getShadowTechnique, &osgShadow::ShadowedScene::setShadowTechnique);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgShadow::ShadowedScene::getDataVariance, &osgShadow::ShadowedScene::setDataVariance, osg_object_datavariance);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgShadow::ShadowedScene::getDescriptions, (setDescriptionsFN)&osgShadow::ShadowedScene::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowedScene::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowedScene::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgShadowShadowedScene::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowedScene::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowedScene::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgShadow::ShadowedScene, RefosgShadowShadowedScene> _registerRefosgShadowShadowedScene;
