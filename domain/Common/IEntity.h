#ifndef IENTITY_H
#define IENTITY_H

namespace booksa {

  class IEntity {
  private:
    unsigned long int id_;
  public:
    virtual ~IEntity();
    virtual unsigned long int getId() = 0;
    virtual void setId(unsigned long int new_id) = 0;
  protected:
    IEntity(unsigned long int id) {id_ = id;}
  };

} // namespace booksa
#endif // IENTITY_H
