#include "finances/entities/operation.hpp"

namespace finances::entities
{
   Operation::Operation(utils::types::ID id_, utils::types::BigDecimal cost_, OperationType type_)
      : m_id(id_), m_cost(cost_), m_type(type_)
   {

   }
   finances::utils::types::ID Operation::GetID() const noexcept
   {
      return m_id;
   }
   utils::types::BigDecimal Operation::GetCost() const noexcept 
   {
      return m_cost;
   }
   OperationType Operation::GetType() const noexcept 
   {
      return m_type;
   }
}