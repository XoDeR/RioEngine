#ifndef COMPONENTMAPPER_H
#define COMPONENTMAPPER_H

#include "EntityManager.h"
#include "World.h"

  template<typename c>
  class ComponentMapper 
  {
    
  private:
    
    EntityManager * em;
    
  public:
    
    ~ComponentMapper() {
      //Not the owner. Only a pointer to.
      em = NULL;
    }
    
    void init(World& world){
      em = world.getEntityManager();
    }
    
    /**
     *Returns the component mapped to the Entity.
     *If there is no such component associated with the entity
     *NULL is returned.
     */
    c * get(Entity & e) {
      //ATTN perhaps pointing to the component bag is faster.
      return (c*)em->getComponent<c>(e);
    }
    
  };
#endif
