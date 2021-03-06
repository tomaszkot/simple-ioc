#include "stdafx.h"
#include <string>
#include "container.h"
#include <assert.h>
#include <iostream>

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

class IB
{
public:
  virtual int id() const = 0;
  virtual void setId(int name) = 0;
};

class B : public IB
{
public:
  enum { invalid_id = -1 };
private:
  int m_id = invalid_id;
public:

  virtual int id() const override
  {
    return m_id;
  }

  virtual void setId(int id) override
  {
    m_id = id;
  }
};

using namespace simple_ioc;

int main()
{
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

  auto objB1 = container::resolve<IB>();
  assert(objB1->id() == B::invalid_id);
  objB1->setId(1);
  assert(objB1->id() == 1);

  std::cout << "all done, press any key to close console";
  getchar();

  return 0;
}

