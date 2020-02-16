#ifndef ENTITY_H
#define ENTITY_H

namespace booksa {

  class Entity {
  private:
    unsigned int id_ = 0;
  public:
    Entity() = delete;
    explicit Entity(unsigned int id) : id_(id){}
    virtual ~Entity();
    unsigned int getId() {return id_;}
  };

} // namespace booksa
#endif // ENTITY_H
