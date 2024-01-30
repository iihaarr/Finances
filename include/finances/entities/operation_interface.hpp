#ifndef __ENTITIES_OPERATION_INTERFACE_HPP__
#define __ENTITIES_OPERATION_INTERFACE_HPP__

#include "finances/utils/types.hpp"

namespace finances::entities
{
   enum class OperationType
   {
      Income, Expenses
   };

   struct IOperation
   {
      virtual finances::utils::types::ID GetID() const noexcept = 0;
      virtual finances::utils::types::BigDecimal GetCost() const noexcept = 0;
      virtual OperationType GetType() const noexcept = 0;
      virtual ~IOperation() = default;
   };
}

#endif