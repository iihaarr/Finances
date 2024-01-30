#ifndef __ENTITIES_CATEGORY_HPP__
#define __ENTITIES_CATEGORY_HPP__

#include "finances/entities/category_interface.hpp"

namespace finances::entities
{
   struct Category : public ICategory
   {
      Category(utils::types::ID id_, std::string name_);
      Category(const Category&) = default;
      Category(Category&&) = default;
      Category& operator=(const Category&) = default;
      Category& operator=(Category&&) = default;

      finances::utils::types::ID GetID() const noexcept override;
      const std::string& GetName() const noexcept override;
      std::unique_ptr<ICategory> Clone() const noexcept override;
      virtual ~Category() = default;
   private:
      utils::types::ID m_id;
      std::string m_name;
   };
}

#endif