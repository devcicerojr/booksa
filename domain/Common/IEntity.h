#ifndef IENTITY_H
#define IENTITY_H

namespace booksa {

  class IEntity {
  private:
    unsigned long int id_;
  public:
    IEntity() : id_(0) {};
    virtual ~IEntity() = 0;
    unsigned long int getId() const {return id_;}
    void setId(unsigned long int new_id) {id_ = new_id;}
  protected:
    IEntity(unsigned long int id) {id_ = id;}
  };

} // namespace booksa
#endif // IENTITY_H
