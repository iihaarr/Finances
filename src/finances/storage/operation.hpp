#ifndef __STORAGE_OPERATION_HPP__ 
#define __STORAGE_OPERATION_HPP__

#include <vector>

#include "finances/storage/operation_interface.hpp"

namespace finances::storage
{
   class OperationStorage : public IOperationStorage
   {
   public:
      std::unique_ptr<entities::IOperation> GetOperationById(utils::types::ID id_) const noexcept override;
      virtual ~OperationStorage() = default;
   private:
      std::vector<std::unique_ptr<entities::IOperation>> m_storage;
   };
}
#endif