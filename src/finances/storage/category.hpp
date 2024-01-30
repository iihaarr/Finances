#ifndef __STORAGE_CATEGORY_HPP__ 
#define __STORAGE_CATEGORY_HPP__

#include <vector>

#include "finances/storage/category_interface.hpp"

namespace finances::storage
{
   class CategoryStorage : public ICategoryStorage
   {
   public:
      std::unique_ptr<entities::ICategory> GetCategoryById(utils::types::ID id_) const noexcept override;
      virtual ~CategoryStorage() = default;
   private:
      std::vector<std::unique_ptr<entities::ICategory>> m_storage;
   };
}
#endif