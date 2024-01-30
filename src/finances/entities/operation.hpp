#ifndef __ENTITIES_OPERATION_HPP__
#define __ENTITIES_OPERATION_HPP__

#include "finances/entities/operation_interface.hpp"

namespace finances::entities
{
   struct Operation : public  IOperation
   {
      Operation(utils::types::ID id_, utils::types::BigDecimal cost_, OperationType type_);
      finances::utils::types::ID GetID() const noexcept;
      utils::types::BigDecimal GetCost() const noexcept override;
      OperationType GetType() const noexcept override;
      virtual ~Operation() = default;
   private:
      utils::types::ID m_id;
      utils::types::BigDecimal m_cost;
      OperationType m_type;
   };
}

#endif