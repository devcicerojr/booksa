#ifndef IENTITY_H
#define IENTITY_H

namespace booksa {

  class IEntity {
  private:
    unsigned long int id_ = 0;
  public:
    virtual ~IEntity();
    unsigned long int getId() const {return id_;}
    void setId(unsigned long int new_id) {id_ = new_id;}

  protected:
    explicit IEntity(unsigned long int id=0) : id_(id){}

  };

} // namespace booksa
#endif // IENTITY_H
