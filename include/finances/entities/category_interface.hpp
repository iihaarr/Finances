#ifndef __ENTITIES_CATEGORY_INTERFACE_HPP__
#define __ENTITIES_CATEGORY_INTERFACE_HPP__

#include <string>

#include "finances/utils/types.hpp"

namespace finances::entities
{
   struct ICategory
   {
      virtual finances::utils::types::ID GetID() const noexcept = 0;
      virtual  const std::string& GetName() const noexcept = 0;
      virtual std::unique_ptr<ICategory> Clone() const noexcept = 0;
      virtual ~ICategory() = default;
   };
}

#endif