#ifndef __ENTITIES_ACCOUNT_INTERFACE_HPP__
#define __ENTITIES_ACCOUNT_INTERFACE_HPP__

#include "finances/utils/types.hpp"

namespace finances::entities
{
   struct IAccount
   {
      virtual finances::utils::types::ID GetID() const noexcept = 0;
      virtual std::string GetName() const noexcept = 0;
   };
}

#endif