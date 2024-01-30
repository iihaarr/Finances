#ifndef __STORAGE_CATEGORY_INTERFACE_HPP__
#define __STORAGE_CATEGORY_INTERFACE_HPP__

#include "finances/entities/category_interface.hpp"

namespace finances::storage
{
   struct ICategoryStorage
   {
      virtual std::unique_ptr<entities::ICategory> GetCategoryById(utils::types::ID id_) const noexcept = 0;
      virtual utils::types::ID CreateCategory(const std::string& name_)  noexcept = 0;
      virtual ~ICategoryStorage() = default;
   };

   ICategoryStorage& GetCategoryStorage();
}

#endif