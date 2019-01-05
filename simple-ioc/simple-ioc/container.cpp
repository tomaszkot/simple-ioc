#include "stdafx.h"
#include "container.h"

std::map<const std::type_info*, std::function<std::shared_ptr<void>(void)>> simple_ioc::container::m_map;