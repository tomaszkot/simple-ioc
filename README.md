# simple-ioc

The simplest possible IOC in cpp.

Usage:
  ```
  //prepare some test stuff
  class IA
  {
  public:
    virtual std::string name() const = 0;
    virtual void setName(std::string name) = 0;
  };

  class A : IA
  {
  public:
    virtual std::string name() const override { return m_name; }
    virtual void setName(std::string s) override { m_name = s; }
  private:
    std::string m_name;
  };

  //test container
  container::registerType<IA, A>();
  container::registerType<IB, B>();

  auto objA1 = container::resolve<IA>();
  objA1->setName("a1");
  assert(objA1->name() == "a1");

  auto objA2 = container::resolve<IA>();
  assert(objA2->name() == "");
  objA2->setName("a2");
  assert(objA2->name() == "a2");
  assert(objA1->name() == "a1");
  ```
