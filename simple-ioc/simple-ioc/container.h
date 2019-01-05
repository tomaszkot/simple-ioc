#pragma once

#pragma once
#include <map>
#include <functional>
#include <memory>

namespace simple_ioc
{
  class container
  {
    static std::map<const std::type_info*, std::function<std::shared_ptr<void>(void)>> m_map;
  public:

    template<typename Itf, typename Imp>
    static void registerType()
    {
      m_map[&typeid(Itf)] = [] {return std::make_shared<Imp>(); };
    }

    template<typename Itf>
    static std::shared_ptr<Itf> resolve()
    {
      return std::static_pointer_cast<Itf>(m_map[&typeid(Itf)]());

    }
  };
}
