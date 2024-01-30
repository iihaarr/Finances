#include "finances/entities/category.hpp"

namespace finances::entities
{
   Category::Category(utils::types::ID id_, std::string name_)
      : m_id(id_), m_name(name_)
   {

   }
   finances::utils::types::ID Category::GetID() const noexcept
   {
      return m_id;
   }
   const std::string& Category::GetName() const noexcept
   {
      return m_name;
   }
   std::unique_ptr<ICategory> Category::Clone() const noexcept
   {
      return std::make_unique<Category>(*this);
   }
}